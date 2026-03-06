class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        //dijkstra : 
        vector <int> move = {0,1,0,-1,0}; // clockwise rotation take i and i+1 movement
        priority_queue <
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,
            greater <pair<int, pair<int, int>>>
        > pq; // distance, row, col
        pq.push({0, {0,0}});
        vector <vector<int>> dist(n, vector <int> (m, INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first, r = it.second.first, c = it.second.second;
            if(d > dist[r][c]) continue;
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + move[i], nc = c + move[i+1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int newD = max(d, abs(heights[nr][nc]-heights[r][c]));
                if(dist[nr][nc] > newD){
                    dist[nr][nc] = newD;
                    pq.push({newD, {nr, nc}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};