class Solution {
public:
void dfs(int node, vector <vector <int>> &adj, vector<int> &vis, int n){
        if(vis[node] == 1) return;
        vis[node] = 1;
        for(int nxt = 0 ; nxt < n ; nxt++){
            if(nxt != node && adj[node][nxt] == 1){
                dfs(nxt,adj,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector <int> vis(n,0);
        int ans = 0;
        for(int node = 0 ; node < n ; node++){
            if(vis[node] == 0){
                ans++;
                dfs(node, adj, vis, n);
            }
        }
        return ans;
    }
};