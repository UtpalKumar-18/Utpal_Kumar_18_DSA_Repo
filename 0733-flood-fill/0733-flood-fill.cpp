class Solution {
    private:
        void bfs(vector<vector<int>> &image,int sr,int sc, int color,vector<vector<int>> &vis){
            int n = image.size();
            int m = image[0].size();
            vis[sr][sc] = 1;
            queue<pair<int,int>> q;
            q.push({sr,sc});
            int initial_pix = image[sr][sc];
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(image[row][col] == initial_pix){
                    image[row][col] = color;
                }

                if(row-1 >=0 && row-1<n && col>=0 && col<m && image[row-1][col] == initial_pix && !vis[row-1][col]){
                    vis[row-1][col] =1;
                    q.push({row-1,col});
                }

                if(row+1 >=0 && row+1<n && col>=0 && col<m && image[row+1][col]== initial_pix && !vis[row+1][col]){
                    vis[row+1][col] =1;
                    q.push({row+1,col});
                }

                if(row >=0 && row <n && col-1>=0 && col-1<m && image[row][col-1] == initial_pix && !vis[row][col-1]){
                    vis[row][col-1] =1;
                    q.push({row,col-1});
                }

                if(row>=0 && row<n && col+1>=0 && col+1<m && !vis[row][col+1] && image[row][col+1] == initial_pix){
                    vis[row][col+1] =1;
                    q.push({row,col+1});
                }

            }
        }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bfs(image,sr,sc,color,vis);
        return image;
    }
};