class Solution {
public:
    // int dp[25][25];
    // bool func(int i, int j, string &s, string &t){
    //     int n = s.length(), m = t.length();
    //     if(j == m) return (i == n);
    //     if(dp[i][j] != -1) return dp[i][j];
    //     bool match = (i<n)&&((s[i]==t[j])||(t[j] == '.'));
    //     if(j+1 < m && t[j+1] == '*'){
    //         return dp[i][j] = (func(i, j+2, s, t) || (match && func(i+1, j, s, t) ));
    //     } 
    //     return dp[i][j] = match&&func(i+1, j+1,s,t);
    // }
    bool isMatch(string s, string p) {
        // memset(dp, -1, sizeof(dp));
        // return func(0,0,s,p);
        int n = s.length(), m = p.length();
        vector <vector <bool>> dp(n+1, vector <bool> (m+1, false));
        dp[n][m] = true;
        for(int i = n ; i >= 0 ; i--){
            for(int j = m-1; j >= 0 ; j--){
                bool match = (i<n)&&((s[i]==p[j])||(p[j] == '.'));
                if(j+1 < m && p[j+1] == '*') dp[i][j] = dp[i][j+2]||(match && dp[i+1][j]);
                else dp[i][j] = match&&dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};