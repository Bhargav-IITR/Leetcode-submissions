class Solution {
public:
    vector <vector <int>> ans;
    int t = 0;
    void dfs(int node, int parent, vector <int> &tin, vector <int> &low, vector <vector <int>> &adj, vector <int> &vis){
        tin[node] = t;
        low[node] = t;
        vis[node] = 1;
        t++;
        for(auto adNode : adj[node]){
            if(adNode == parent) continue;
            if(vis[adNode]){
                //just update the low
                low[node] = min(low[node], low[adNode]);
            }else{
                dfs(adNode, node, tin, low, adj, vis);
                low[node] = min(low[node], low[adNode]);
                // if low[adNode] <= tin[node] -> not a bridge
                if(low[adNode] > tin[node]){
                    ans.push_back({node, adNode});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector<int>> adj(n, vector <int> ());
        for(auto connection : connections){
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector <int> tin(n, INT_MAX);
        vector <int> low(n, INT_MAX);
        vector <int> vis(n, 0);
        dfs(0, 0, tin, low, adj, vis);
        return ans;
    }
};