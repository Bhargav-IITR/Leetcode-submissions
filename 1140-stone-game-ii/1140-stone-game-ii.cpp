class Solution {
public:
    pair<int, int> dp[101][2][102];

    pair<int, int> func(int i, int turn, int m, vector<int>& piles) {
        int n = piles.size();

        if (i >= n) return {0, 0};

        if (dp[i][turn][m] != make_pair(-1, -1))
            return dp[i][turn][m];

        int sum = 0;
        int X = 2 * m;

        pair<int, int> ans = {-1, -1};
        int maxi = INT_MIN;

        for (int k = i; k < min(i + X, n); k++) {
            sum += piles[k];

            auto p = func(
                k + 1,
                turn ^ 1,
                max(m, k - i + 1),
                piles
            );

            if (turn) { // Alice
                int aliceScore = sum + p.first;

                if (aliceScore > maxi) {
                    maxi = aliceScore;
                    ans = {aliceScore, p.second};
                }
            }
            else { // Bob
                int bobScore = sum + p.second;

                if (bobScore > maxi) {
                    maxi = bobScore;
                    ans = {p.first, bobScore};
                }
            }
        }

        return dp[i][turn][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));

        auto ans = func(0, 1, 1, piles);

        return ans.first;
    }
};