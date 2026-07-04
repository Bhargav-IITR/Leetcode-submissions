class Solution {
public:
    int ans = INT_MAX;
    void dfs(int node, vector <vector <pair<int, int>>> &roads, vector <int> &vis){
        vis[node] = 1;
        for(auto road : roads[node]){
            int node2 = road.first, dist = road.second;
            ans = min(ans, dist);
            if(vis[node2] == 0) dfs(node2, roads, vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {

        vector <vector <pair <int, int>>> p(n, vector <pair<int, int>> ());
        for(auto road : roads){
            int a = road[0], b = road[1], w = road[2];
            p[a-1].push_back({b-1, w});
            p[b-1].push_back({a-1,w});
        }
        vector <int> vis(n, 0);
        dfs(0, p, vis);
        return ans;
    }
};