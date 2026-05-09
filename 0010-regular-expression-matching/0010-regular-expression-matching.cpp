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
        vector <bool> next(m+1, false);
        next[m] = true;
        for(int i = n ; i >= 0 ; i--){
            vector <bool> curr(m+1, false);
            curr[m] = (i == n);
            for(int j = m-1; j >= 0 ; j--){
                bool match = (i<n)&&((s[i]==p[j])||(p[j] == '.'));
                if(j+1 < m && p[j+1] == '*') curr[j] = curr[j+2]||(match && next[j]);
                else curr[j] = match&&next[j+1];
            }
            next = curr;
        }
        return next[0];
    }
};