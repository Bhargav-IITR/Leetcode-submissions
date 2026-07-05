#define ll long long
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        if(edges.size() == 0) return -1;
        vector <vector <int>> lst;
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(online[u] && online[v]){
                lst.push_back({w, u, v});
            }
        }
        
        sort(lst.begin(), lst.end());
        int lo = 0, hi = lst.size()-1;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            //Does there exist a path whose minimum edge weight is AT LEAST lst[mid][0]?
            if(possible(mid, lst, online.size(), k)) {
                ans = mid;
                lo = mid+1;
            }  else{
                hi = mid-1;
            }
        }
        if(ans == -1) return -1;
        return lst[ans][0];
    }

    bool possible(int id, vector <vector <int>> &edges, int n, ll k){
        vector <vector <pair <int, int>> > adj(n, vector <pair<int, int>> ());
        int ui = edges[id][1], vi = edges[id][2], ci = edges[id][0];
        for(int i = id ; i < edges.size() ; i++){
            auto edge = edges[i];
            int u = edge[1], v = edge[2], w = edge[0];
            adj[u].push_back({v, w});
        }
        ll dist = dijkstra(adj, 0, k);
        return (dist <= k);
    }

    ll dijkstra(vector <vector <pair<int, int>>> &adj, int src, int k){
        int n = adj.size();
        vector <ll> dist(n, LLONG_MAX);
        dist[src] = 0;
        priority_queue <pair<ll, ll>, vector <pair<ll, ll>> , greater <pair<ll, ll>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ll d = top.first , node = top.second;
            // Ignore stale entries
            if (d > dist[node]) continue;

            // Shortest path to destination found
            if (node == n-1) return d;

            if(dist[node] < d) continue;
            for(auto adjNode : adj[node]){
                ll node2 = adjNode.first , wt = adjNode.second;
                if(dist[node2] > d + wt){
                    dist[node2] = d+wt;
                    pq.push({d+wt, node2});
                }
            }
        }
        return LLONG_MAX;
    }

};