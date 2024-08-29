class Solution {
public:
    bool pos(int nr, int nc, int n){
        return (nr >= 0 && nr < n && nc >= 0 && nc < n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector <vector <int>> dist(n, vector <int> (n, INT_MAX));
        dist[0][0] = 1;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {wt, {i, j}}

        pq.push({0, {0,0}});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int r = p.second.first, c = p.second.second;
            for(auto it : moves){
                int nr = r + it.first, nc = c + it.second;
                if(pos(nr,nc,n) && dist[nr][nc] > dist[r][c]+1 && grid[nr][nc] == 0){
                    dist[nr][nc] = dist[r][c]+1;
                    pq.push({dist[nr][nc], {nr,nc}});
                }
            }
        }
        int ans = dist[n-1][n-1];
        if(ans == INT_MAX) return -1;
        return ans;
    }
};