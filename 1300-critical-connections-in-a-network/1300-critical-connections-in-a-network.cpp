class Solution {
public:
int timer = 0;
    void dfs(int node, int parent, vector <int> &vis, vector <vector<int>> &ad, vector<int> &tin, vector<int> &low, vector <vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = timer, low[node] = timer;
        timer++;
        for(auto it : ad[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, ad, tin, low, bridges);
                if(low[it] > tin[node]) bridges.push_back({it, node});
                low[node] = min(low[node], low[it]);
            }else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector <int>> ad(n);
        for(auto it : connections){
            ad[it[0]].push_back(it[1]);
            ad[it[1]].push_back(it[0]);
        }
        vector <int> vis(n, 0);
        vector <int> tin (n);
        vector<int> low(n);
        vector <vector <int>> bridges;
        dfs(0, -1, vis, ad, tin, low, bridges);
        return bridges;
    }
};