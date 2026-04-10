class Solution {
public:
void fun(int i,vector<vector<int>> & isConnected ,vector<bool> &bol){
    bol[i]=true;
    for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1 && !bol[j]){
               fun(j,isConnected,bol);
            }
        
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n=isConnected.size();
        int node=0;
        int m=isConnected[0].size();
        int res=0;
vector<bool> bol(n, 0);
for(int i=0;i<n;i++){
    if(!bol[i]){
        fun(i,isConnected,bol);
        res++;
    }
}
return res;
    }
};