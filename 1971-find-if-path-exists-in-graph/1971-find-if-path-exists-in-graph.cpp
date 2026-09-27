class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<vector<int>> adj(n);
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);       
            }
            vector<int> vis(n,0);
            vis[source] = 1;
            queue<int> q;
            q.push(source);
            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            if(vis[destination]) return true;
            else return false;
    }
};