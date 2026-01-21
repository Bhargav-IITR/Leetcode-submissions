class Solution {
public:
    int l;
    string ans;
    int m,n;
    int dp[10][10][20];

    bool func(int i, int j, vector <vector <char>> &board, vector <vector <int>> &vis, int id){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        
        if(vis[i][j] == 1) return false;
        vis[i][j] = 1;
        if(board[i][j] != ans[id]){
            vis[i][j] = 0;
            return false;   
        }
        if(id == l-1){
            vis[i][j] = 0;
            return true;
        }

        if(func(i+1, j, board, vis, id+1) | func(i-1, j, board, vis, id+1) | func(i, j+1, board, vis, id+1) | func(i, j-1, board, vis, id+1)) return true;

        vis[i][j] = 0;

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        l = word.length();
        ans = word;
        m = board.size(), n = board[0].size();
        memset(dp, -1, sizeof(dp));
        vector <vector <int>> vis(m, vector <int> (n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0] && func(i,j, board, vis, 0) == true) return true;
            }
        }
        return false;
    }
};