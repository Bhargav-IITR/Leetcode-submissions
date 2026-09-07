class Solution {
public:
    int dp[501][501];
    int func(int i, int j, vector <int> &piles){
        if(i > j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int op1 = piles[i] - func(i+1, j, piles);
        int op2 = piles[j] - func(i, j-1, piles);
        return dp[i][j] = max(op1, op2);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        int ans = func(0, n-1, piles);
        return ans > 0;
    }
};