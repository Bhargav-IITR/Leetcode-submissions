class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> dist(n, INT_MAX);
        vector <vector<vector <int>>> adj(n, vector <vector<int>> ());
        for(auto flight : flights){
            int u = flight[0], v = flight[1], price = flight[2];
            adj[u].push_back({v, price});
        }
        dist[src] = 0;
        if(src == dst) return 0;
        queue <vector <int>> q; // stops, node, dist
        q.push({0, src, 0});
        while(!q.empty()){
            vector <int> front = q.front();
            q.pop();
            int stops = front[0], node = front[1], p = front[2];
            if(stops == k+1) continue;
            for(auto flight : adj[node]){
                int v = flight[0], price = flight[1];
                if(dist[v] > p + price){ // relaxation
                    dist[v] = p + price;
                    q.push({stops+1, v, dist[v]});
                }
            }
        }
        return ((dist[dst] == INT_MAX) ? -1 : dist[dst]);
    }
};