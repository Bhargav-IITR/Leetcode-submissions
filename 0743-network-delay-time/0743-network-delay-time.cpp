class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <int> dist(n+1, INT_MAX);
        dist[k] = 0;
        vector <vector<pair<int, int>>> adj(n+1, vector <pair<int,int>> ());
        for(auto time : times){
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        priority_queue <
            pair <int, int>,
            vector <pair<int,int>>,
            greater <pair<int, int>>
        > pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second, d = it.first;
            if(dist[node] < d) continue;
            for(auto adjNode : adj[node]){
                int adjN = adjNode.first, time = adjNode.second;
                int newTime = d + time;
                if(dist[adjN] > newTime){
                    dist[adjN] = newTime;
                    pq.push({newTime, adjN});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            int it = dist[i];
            if(it == INT_MAX) return -1;
            ans = max(ans, it);
        }
        return ans;
    }
};