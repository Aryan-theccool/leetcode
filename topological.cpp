class Solution {
  public:
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n=edges.size();
        vector<vector<int>> adj(V);
        vector<int> indgree(V);
        queue<int> q;
        vector<int> res;
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
                        int des =edges[i][1];
        adj[src].push_back(des);
        indgree[des]++;
        }
        for(int i=0;i<indgree.size();i++){
                    if(indgree[i]==0){
                        q.push(i);
                    }

        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<adj[node].size();i++){
               int neigh=adj[node][i];
               indgree[neigh]--;
               if(indgree[neigh]==0){
                   q.push(neigh);
               }
            }
        }
        return res;
    }
};
