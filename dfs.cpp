class Solution {
  public:
  void fun(vector<vector<int>>& adj,int node,vector<int>& res,vector<bool>& bol){
  res.push_back(node);
  bol[node]=true;
  for(int i=0;i<adj[node].size();i++){
      int neigh=adj[node][i];
      if(bol[neigh]==false){
          fun(adj,neigh,res,bol);
      }
  }
  return;
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> res;
        vector<bool> bol(n,0);
     fun(adj,0,res,bol);
        return res;
    }
};

