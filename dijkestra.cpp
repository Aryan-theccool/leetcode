class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //creating a vectore like jisme head is 0 and all is infinit
        // pusing a <distance ,city>
        //process heap untill it becomes empty and then just push all the neigh in min heap
        // d=0;
        // d+w<distance[neigh]
        // heigh=patna ;
        // [
        //     dist[neigh]=d+w;
        //     push<2,patna>
        //     ]
        
        // now take out the minimum dist one from min heap 
        
        
        
        
        // vector<int>dist(n,INT_MAX);
        // vector<vector<pair<int,int>>>a(n);
        // for(int i=0;i<edges.size();i++){
        //     int s=edges[i][0];
        //     int d=edges[i][1];
        //     int w=edges[i][2];
        //     a[s].push_back({d,w});
        //     a[d].push_back({s,w});
        // }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        // dist[s]=0;
        // pq.push({0,s})
        // while(!pq.empty()){
        //   pair<int,int> p=pq.top();
        //   pq.pop();
        //   int d=p.first;
        //   int node=p.second;
        //   if(d>dist[node]){
        //       continue;
        //   }
        //   for(int j=0;j<a[node].size();j++){
        //       int neigh=a[node][j].first;
        //       int wt=a[node][j].second;
        //       if(d+w<dist[neigh]){
        //           dist[neigh]=w+d;
        //           pq.push({d+w,neigh});
        //       }
              
        //   }
        // }
        
        vector<int>dist(V,INT_MAX);
        vector<vector<pair<int,int>>>a(V);
        
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            int w=edges[i][2];
            
            a[s].push_back({d,w});
                        a[d].push_back({s,w});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        dist[src]=0;
        pq.push_back({0,src});
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int d=p.first;
            int node=p.second;
            
            if(d>dist[node])
            continue;
            
            for(int j=0;j<a[node].size();j++){
                int neigh=a[node][j].first;
                int wt=a[node][j].second;
                
                if(wt+d<dist[neigh]){
                    
                    dist[neigh]=d+wt;
                    pq.push({dist[neigh],neigh});
                    
                }
            }
            
        }
        
        return dist;
        
        
    }
};
