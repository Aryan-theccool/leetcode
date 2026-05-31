class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans;
        vector<int>dist(n,INT_MAX);
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++){
            int s=times[i][0];
            int d=times[i][1];
            int w=times[i][2];

            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){

            auto p=pq.top();
            pq.pop();

            int d=p.first;
            int node =p.second;

            if(d>dist[node]){
                continue;
            }
            for(int j=0;j<a[node].size();j++)
{
    int neigh=a[node][j].first;
    int wt=a[node][j].second;
    if(wt+d<dist[neigh]){
        dist[neigh]=d+wt;
        pq.push({dist[neigh],neigh});
    }
}        }
ans=*max_element(dist.begin(),dist.end());
if(ans==INT_MAX){
    return -1;
}
return ans;
    }
};
