class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector <pair<int,int>>> adj(n);
        for(auto it : flights){
            int u = it[0], v = it[1], cost = it[2];
            adj[u].push_back({v,cost});
        }
        if(adj[src].size() == 0) return -1;
        vector <int> dist(n, INT_MAX);
        queue <pair<int, pair<int,int>>> q; // stops - node - cost
        q.push({0, {src, 0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int stops = p.first, city = p.second.first, cost = p.second.second;
            if(stops == k+1) continue;
            for(auto it : adj[city]){
                int adjCity = it.first, c = it.second;
                if(dist[adjCity] > cost+c){
                    dist[adjCity] = cost + c;
                    q.push({stops+1, {adjCity, dist[adjCity]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];

    }
};