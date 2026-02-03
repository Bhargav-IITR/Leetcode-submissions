class Solution {
public:
int dp[501][501];
    int LCS(int i, int j, string &s, string &t){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1 + LCS(i-1, j-1, s,t);
        int ans = max(LCS(i-1, j, s,t) , LCS(i, j-1, s, t));
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
        return n-LCS(n-1, n-1, s, t);
    }
};