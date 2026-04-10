class Solution {
  public:
//   void fun(vector<vector<int>> &adj,int node,vector<int>& res,vector<bool>& bol){
//       for(int i=0;i<adj[node].size();i++){
//           res.push_back(node);
          
//       }
//   }
    vector<int> bfs(vector<vector<int>> &adj) {
int n=adj.size();
vector<int> res;
vector<bool> bol(n,0);
queue<int>q;
q.push(0);
bol[0]=1;
while(!q.empty()){
    int node=q.front();
    q.pop();
    res.push_back(node);
    for(int i=0;i<adj[node].size();i++){
        int neigh=adj[node][i];
       if( bol[neigh]==false ){
           q.push(neigh);
           bol[neigh]=true;
       }
    }
}
return res;
    }
};