// class Solution {
// public:
// queue<pair<int,int>>qt;
//         int x[4]={-1,1,0,0};
//         int y[4]={0,0,-1,1};

//         bool valid(int i,int j,int n,int m){
// if(i<0 || i>=n || j<0 || j>=m ){
//     return false;
// }
// return true;
//         }
//     int orangesRotting(vector<vector<int>>& grid) {
// int n=grid.size();
// int m=grid[0].size();
// int fresh=0;
// int time=0;
// int i=0,j=0;
//             for(int i=0;i<n;i++){
//             for(int j=0;j<m;i++){
//               if(grid[i][j]==2){
//                 qt.push({i,j});
//                 grid[i][j]=-2;
//               }
//               else if(grid[i][j]==1)
// {fresh++;
//               }
//             }
//         }
//        while(!qt.empty() && fresh>0){
//         time++;
// int s=qt.size();
// pair<int,int> p=qt.front();
// qt.pop();
// int r=p.first;
// int c=p.second;
//  for(int k=0;k<4;k++){
//     int row=i+x[k];
//     int col=c+y[k];

//     if(valid(row,col,n,m) && grid[row][col]==1 ){
//         qt.push({row,col});
//         grid[row][col]=-2;
//         fresh--;
//     }
//  }
//        }
//        if (fresh>0){
//         return -1;
//        }
//        return time;
//     }
// };

class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> qt; // ✅ moved here

        int fresh = 0;
        int time = 0;

        // 🔹 Step 1: fill queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){   // ✅ fixed j++
                if(grid[i][j]==2){
                    qt.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        // 🔹 Step 2: BFS
        while(!qt.empty() && fresh > 0){
            int s = qt.size();
            time++;

            for(int i=0;i<s;i++){   // ✅ process whole level
                auto p = qt.front();
                qt.pop();

                int r = p.first;
                int c = p.second;

                for(int k=0;k<4;k++){
                    int row = r + x[k];   // ✅ fixed
                    int col = c + y[k];

                    if(valid(row,col,n,m) && grid[row][col]==1){
                        qt.push({row,col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }
        }

        if(fresh > 0) return -1;

        return time;
    }
};