class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if(board[i][j] == 'X' || board[i][j] == '1') return;
        board[i][j] = '1';
        dfs(i-1,j,board);
        dfs(i+1,j,board);
        dfs(i,j-1,board);
        dfs(i,j+1,board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0 ; i < m ; i++) if(board[i][0] == 'O') dfs(i,0,board);
        for(int i = 0 ; i < m ; i++) if(board[i][n-1] == 'O') dfs(i,n-1,board);
        for(int j = 0 ; j < n ; j++) if(board[0][j] == 'O') dfs(0,j,board);
        for(int j = 0 ; j < n ; j++) if(board[m-1][j] == 'O') dfs(m-1,j,board);
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};