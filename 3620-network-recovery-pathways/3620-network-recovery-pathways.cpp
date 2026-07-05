#define ll long long
class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        if(edges.size() == 0) return -1;
        set <int> st;
        int n = online.size();
        adj.assign(n, {});
        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(online[u] && online[v]){
                st.insert(w);
                adj[u].push_back({v,w});
            }
        }
        
        vector <int> wt(st.begin(), st.end());
        int lo = 0, hi = wt.size()-1;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            //Does there exist a path whose minimum edge weight is AT LEAST lst[mid][0]?
            if(possible(wt[mid], online.size(), k)) {
                ans = wt[mid];
                lo = mid+1;
            }  else{
                hi = mid-1;
            }
        }
        return ans;
    }

    bool possible(int wt, int n, ll k){
        return dijkstra(wt, n, k);
    }

    bool dijkstra(int minWt, int n, ll k){
        vector <ll> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue <pair<ll, ll>, vector <pair<ll, ll>> , greater <pair<ll, ll>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ll d = top.first , node = top.second;
            // Ignore stale entries
            if(d > k) return false;
            if (d > dist[node]) continue;

            // Shortest path to destination found
            if (node == n-1) return true;

            if(dist[node] < d) continue;
            for(auto adjNode : adj[node]){
                ll node2 = adjNode.first , wt = adjNode.second;
                if (wt < minWt)
                    continue;
                if(dist[node2] > d + wt){
                    dist[node2] = d+wt;
                    pq.push({d+wt, node2});
                }
            }
        }
        return false;
    }

};