class Solution {
public: 
    void dfs(int v, vector<int> &vis, vector <vector <int>> &isConnected){
        int n = vis.size();
        for(int adj = 0 ; adj < n ; adj++){
            if(isConnected[v][adj] &&(v != adj)){
                if(vis[adj] == 0){
                    vis[adj] = 1;
                    dfs(adj, vis, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // givem is adjacency matrix 
        int n = isConnected.size();
        vector <int> vis(n, 0);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                ans++;
                vis[i] = 1;
                dfs(i, vis, isConnected);
            }
        }
        return ans;
    }
};