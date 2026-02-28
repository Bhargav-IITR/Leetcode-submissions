class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue <pair<int,int>> q;
        bool freshPresent = false;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j}); 
                }
                if(grid[i][j] == 1) freshPresent = true;
            }
        }
        if(q.empty()){
            if(freshPresent)return -1;
            return 0;
        }
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int node = 1 ; node <= size ; node++){
                auto f = q.front();
                q.pop();
                int i = f.first, j = f.second;
                if(i-1 >= 0 &&  grid[i-1][j] == 1){
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                }
                if(i+1 < m &&  grid[i+1][j] == 1){
                    q.push({i+1,j});
                    grid[i+1][j] = 2;
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                }
                if(j+1 < n && grid[i][j+1] == 1){
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                }
            }
            ans++;
        }
        for(int i = 0 ; i < m ; i++) for(int j = 0 ; j < n ; j++) if(grid[i][j] == 1) return -1;
        return ans-1;   
    }
};