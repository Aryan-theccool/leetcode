class Solution {
public:
bool valid(int i,int j,int n, int m){
    if(i<0 || j<0 || i>=n || j>=m ){
        return false;
    }
    return true;
}
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};

void dfs(vector<vector<char>>& grid ,int n,int m, int i,int j,vector<vector<bool>> & bol){
    bol[i][j]=1;
    for(int k=0;k<4;k++){
        int row=i+x[k];
                int col=j+y[k];
        if(valid(row,col,n,m) && grid[row][col]=='1' && bol[row][col]==false){
        dfs(grid,n,m,row,col,bol) ;

        }
          }
          return ;
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        int i,j;
        vector <vector<bool>>bol(n);
        for(int i=0;i<n;i++){
            vector<bool> t(m,0);
            bol[i]=t;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && bol[i][j]==0){
                    dfs(grid,n,m,i,j,bol);
                    res++;
                }
            }
        }
        return res;
            }
};