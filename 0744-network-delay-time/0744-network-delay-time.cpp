class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector <pair<int,int>>> adj(n);
        for(auto it : times){
            int u = it[0]-1, v = it[1]-1, w = it[2];
            adj[u].push_back({v,w});
        }

        priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>>> q;
        vector <int> dist(n,INT_MAX);
        dist[k-1] = 0;
        q.push({0,k-1});
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int wt = p.first, node = p.second;
            for(auto it: adj[node]){
                int adjNode = it.first, edge = it.second;
                if(dist[adjNode] > wt + edge){
                    dist[adjNode] = wt+edge;
                    q.push({wt+edge, adjNode});
                }
            }
        }
        int mn = INT_MIN;
        for(auto it : dist) mn = max(mn, it);
        if(mn == INT_MAX) return -1;
        return mn;
    }

};