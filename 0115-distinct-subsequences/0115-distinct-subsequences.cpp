class Solution {
public:
    int dp[1001][1001];
    int func(int i, int j, string &s, string &t){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int notMatch = func(i+1,j,s,t);
        int match = 0;
        if(s[i] == t[j]) match = func(i+1,j+1,s,t);
        return dp[i][j] = match+notMatch;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return func(0,0,s,t);
    }
};