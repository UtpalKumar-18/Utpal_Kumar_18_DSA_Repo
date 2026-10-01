class Solution {
    private:
        void bfs(vector<vector<char>> &grid,vector<vector<int>> &visit,int n, int m,int row ,int col){
            queue<pair<int,int>> q;
            q.push({row,col});
            visit[row][col] =1;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                int delrow = node.first;
                int delcol = node.second;

                if(delrow-1>=0 && delrow-1<n && delcol >=0 && delcol<m && grid[delrow-1][delcol] == '1' && !visit[delrow-1][delcol]){
                    q.push({delrow-1,delcol});
                    visit[delrow-1][delcol] = 1;
                }
                if(delrow>=0  && delrow<n && delcol-1 >=0 && delcol-1<m && grid[delrow][delcol-1] == '1'&& !visit[delrow][delcol-1] ){
                     q.push({delrow,delcol-1});
                     visit[delrow][delcol-1] = 1;
                }
                if(delrow>=0 && delrow<n  && delcol+1 >=0 && delcol+1 <m && grid[delrow][delcol+1] == '1' && !visit[delrow][delcol+1]) {
                    q.push({delrow,delcol+1});
                    visit[delrow][delcol+1] = 1;
                    }
                if(delrow+1>=0 && delrow+1<n && delcol >=0 && delcol<m && grid[delrow+1][delcol] == '1' && !visit[delrow+1][delcol]){
                    q.push({delrow+1,delcol});
                    visit[delrow+1][delcol] = 1;
                } 


            }
        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n,vector<int>(m,0));
        int cnt =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    cnt++;
                    bfs(grid,visit,n,m,i,j);
                }
            }
        }
        return cnt;
    }
};