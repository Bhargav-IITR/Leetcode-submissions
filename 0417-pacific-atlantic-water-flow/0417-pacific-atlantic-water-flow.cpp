class Solution {
public: 
    vector <int> moves = {-1,0,1,0,-1};
    void dfs(int i, int j, vector <vector <int>> &h, vector <vector <int>> &vis){
        int m = h.size(), n = h[0].size();
        vis[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++){
            int ni = i+moves[k], nj = j + moves[k+1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && (h[ni][nj] >= h[i][j]) && (vis[ni][nj] == 0)){
                dfs(ni, nj, h, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector <vector<int>> visPac(m, vector <int> (n, 0));
        vector <vector <int>> visAt(m, vector <int> (n, 0));
        for(int i = 0 ; i < n ; i++) if(visPac[0][i] == 0) dfs(0, i, h, visPac);
        for(int i = 1 ; i < m ; i++) if(visPac[i][0] == 0) dfs(i, 0, h, visPac);
        for(int i = 0; i< n ;i++) if(visAt[m-1][i] == 0) dfs(m-1, i, h, visAt);
        for(int i = 0 ; i < m-1 ; i++) if(visAt[i][n-1] == 0) dfs(i, n-1, h, visAt);
        vector <vector <int>> ans;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if((visPac[i][j] == 1) && (visAt[i][j] == 1)) {
                    ans.push_back({i, j});
                }
            }
        }  
        return ans;
    }
};