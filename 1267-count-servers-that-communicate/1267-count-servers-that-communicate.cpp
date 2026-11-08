// class Solution {
// public:
//     void dfs(int n,int m,int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delrow[],int delcol[]){
        
//         for(int i=0;i<4;i++){
//             int drow = row + delrow[i];
//             int dcol = col + delcol[i];
//             if(drow>=0 && drow<n && dcol>=0 && dcol <m && grid[drow][dcol] == 1 && !vis[drow][dcol]){
//                 vis[drow][dcol] = 1;
//                 dfs(n,m,drow,dcol,vis,grid,delrow,delcol);
//             }
//         }
//     }

//     int countServers(vector<vector<int>>& grid) {
//         int cnt =0;
//         int n = grid.size();
//         int m = grid[0].size();
//         int delrow[] = {-1,0,1,0};
//         int delcol[] = {0,1,0,-1};
//          vector<vector<int>> vis(n,vector<int>(m,0));
//          for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     dfs(n,m,i,j,vis,grid,delrow,delcol);
//                 }
//             }
//          }

//          for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j] == 1) cnt++;
//             }
//     }
//          return cnt;
//     }
// };



class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    bool comu_possible = false;

                    for(int col =0;col<m;col++){
                        if(grid[i][col] ==1 && col!=j) {
                            comu_possible = true;
                            break;
                        }
                    }

                    if(comu_possible == true) cnt++;
                    else{
                        for(int row=0;row<n;row++){
                            if(grid[row][j] == 1 && row != i) {
                                comu_possible = true;
                                break;
                            }
                        }
                        if(comu_possible == true) cnt++;
                    }
                }
            }
        }
        return cnt;
        
         
    }
};