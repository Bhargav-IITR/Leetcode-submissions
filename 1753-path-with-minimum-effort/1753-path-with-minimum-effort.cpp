class Solution {
public:
    bool pos(int r, int c, int m, int n){
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    int minimumEffortPath(vector<vector<int>>& height) {
        int m = height.size(), n = height[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {wt, {i, j}}
        pq.push({0, {0,0}});
        vector <vector<int>> effort(m,vector<int>(n,INT_MAX));
        effort[0][0] = 0;
        vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int effortTillNow = p.first;
            int r = p.second.first, c = p.second.second;
            for(auto move : moves){
                int nr = r + move.first, nc = c + move.second;
                if(pos(nr,nc,m,n)){
                    int currEffort = max(effortTillNow, abs(height[nr][nc]-height[r][c]));
                    if(currEffort < effort[nr][nc]){
                        effort[nr][nc] = currEffort;
                        pq.push({currEffort, {nr,nc}});
                    }
                }
            }
        } 
        return effort[m-1][n-1];  
    }
};