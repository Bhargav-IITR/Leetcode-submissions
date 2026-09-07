class Solution {
public:
    int dp[101][102];

    int func(int i, int m, vector<int>& piles) {
        int n = piles.size();

        if (i >= n) return 0;

        if (dp[i][m]!= -1)
            return dp[i][m];

        int sum = 0;
        int X = 2 * m;

        int ans = INT_MIN;

        for (int k = i; k < min(i + X, n); k++) {
            sum += piles[k];

            auto p = func(
                k + 1,
                max(m, k - i + 1),
                piles
            );
            ans = max(ans, sum - p);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
int total = accumulate(piles.begin(), piles.end(), 0);
        auto ans = func(0, 1, piles);

        return (total+ans)>>1;
    }
};