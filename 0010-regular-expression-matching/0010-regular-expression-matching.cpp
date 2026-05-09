class Solution {
public:
    int dp[25][25];
    bool func(int i, int j, string &s, string &t){
        int n = s.length(), m = t.length();
        if(j == m) return (i == n);
        if(dp[i][j] != -1) return dp[i][j];
        bool match = (i<n)&&((s[i]==t[j])||(t[j] == '.'));
        if(j+1 < m && t[j+1] == '*'){
            return dp[i][j] = (func(i, j+2, s, t) || (match && func(i+1, j, s, t) ));
        } 
        return dp[i][j] = match&&func(i+1, j+1,s,t);
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return func(0,0,s,p);
    }
};