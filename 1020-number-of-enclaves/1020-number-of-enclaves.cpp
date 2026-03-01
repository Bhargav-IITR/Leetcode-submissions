class Solution {
public:
void dfs(int i, int j, vector<vector<int>> &board){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] == 0 || board[i][j] == 2) return;
        board[i][j] = 2;
        dfs(i-1,j,board);
        dfs(i+1,j,board);
        dfs(i,j-1,board);
        dfs(i,j+1,board);
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; i++) if(board[i][0] == 1) dfs(i,0,board);
        for(int i = 0 ; i < m ; i++) if(board[i][n-1] == 1) dfs(i,n-1,board);
        for(int j = 0 ; j < n ; j++) if(board[0][j] == 1) dfs(0,j,board);
        for(int j = 0 ; j < n ; j++) if(board[m-1][j] == 1) dfs(m-1,j,board);
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j  = 0 ; j < n ; j++){
                ans += (board[i][j] == 1);
            }
        }
        return ans;
    }
};