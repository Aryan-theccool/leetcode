class Solution {
public:
// bool valid(int i,int j,int n,int m){
//     if(i<0 || i>=n || j<0 || j>=m){
//         return false;
//     }
//     return true;
// }
// bool bfs(vector<vector<int>>& grid,int n ,int m,int money){
//     int i,j;
//     int x[4]={1,-1,0,0};
//     int y[4]={0,0,1,-1};
//     queue<pair<int,int>>q;
//     vector<vector<int>>vis(n);

//     for(int i=0;i<n;i++){
//         vector<int>t(m,0);
//     vis[i]=t;
// }
// if(grid[0][0] > money)
//     return false;
// q.push({0,0});
// vis[0][0]=1;
// while(!q.empty()){
//    auto p=q.front();
//    q.pop(); 
//    int row=p.first;
//    int col=p.second;
//    if(row==n-1 && col==m-1){
//     return true;
//    }for(int k=0;k<4;k++){
//     int r=row+x[k];
//     int c=col+y[k];
//     if(valid(r,c,n,m) && vis[r][c]==0 && money>=grid[r][c]){
//         q.push({r,c});
//         vis[r][c]=1;
    
//     }
  
//    }

// }
//   return false;
// // vector<vector<int> t(n,vector<int> )
// }
bool valid(int i , int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
   int swimInWater(vector<vector<int>>& grid) {
//        int n=grid.size();
//        int m=grid[0].size();
//        int low=grid[0][0];
//        int high=grid[0][0];

//        for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             high=max(high,grid[i][j]);
//         }

//     } 
//     int res=0;
//     while(low<=high){
//         int guess=(low+high)/2;
//     if(bfs(grid,n,m,guess))
//     {
//         res=guess;
//         high=guess-1;
//     }else{
//         low=guess+1;
//     }
//     }
//     return res;
   vector<int> ans;
int n=grid.size();
int m=grid[0].size();
vector<vector<int>> res(n);
for(int i=0;i<n;i++){
    vector<int> t(m,INT_MAX);
    res[i]=t;
}
priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
> pq;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
res[0][0] = grid[0][0];
pq.push({grid[0][0], {0,0}});

while(!pq.empty()){
    auto p=pq.top();
    pq.pop();
    int dis=p.first;
    int row=p.second.first;
    int col=p.second.second;
    if(dis>res[row][col]){
        continue;
    }
    for(int k=0;k<4;k++){
int r=row+x[k];
int c=col+y[k];
if(!valid(r,c,n,m)){
    continue;
}
int newwt = max(dis, grid[r][c]);
if(newwt<res[r][c]){
    res[r][c]=newwt;
    pq.push({newwt,{r,c}});
}

    }
}
return res[n-1][m-1];

    }
};
