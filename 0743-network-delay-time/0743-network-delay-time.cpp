class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <int> dist(n, INT_MAX);
        vector <vector <pair<int, int>>> adj(n, vector <pair<int, int>> ());
        for(auto it : times){
            int u = it[0], v = it[1], w = it[2];
            u--, v--;
            adj[u].push_back({v, w});
        }
        dist[k-1] = 0;
        priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>>> q;
        q.push({0, k-1});
        while(!q.empty()){
            int node = q.top().second;
            int d = q.top().first;
            q.pop();
            if(dist[node] < d) continue; // <<-- optimisationm
            for(auto ad : adj[node]){
                int adNode = ad.first, wt = ad.second;
                if(d + wt < dist[adNode]){
                    dist[adNode] = d+wt;    
                    q.push({dist[adNode], adNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int it = dist[i];
            if(it == INT_MAX) return -1;
            ans = max(ans, it);
        }
        return ans;
    }
};