class Solution {
public:
    void dfs(int i , int j , vector<vector<int>> &vis, vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(grid[i][j] == '0') return;
        if(vis[i][j] == 1) return;
        vis[i][j] = 1;   
        dfs(i-1,j,vis,grid);
        dfs(i+1,j,vis,grid);
        dfs(i,j-1,vis,grid);
        dfs(i,j+1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        int ans = 0;
        for(int i =0;i<m;i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    ans++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};