class Solution {
public:
    int isPal[2005][2005];
    void constructIsPal(string &s){
        int n = s.length();
        for(int i = 0 ; i < n ; i++) isPal[i][i] = 1;
        for(int i = 0 ; i <n-1; i++) isPal[i][i+1] = (s[i] == s[i+1]);
        for(int len = 3 ; len <= n ; len++){
            for(int i = 0 ; i < n ; i++){
                int j = i + len - 1;
                if(j < n) isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
            }
        }
    }

    int dp[2005];
    
    int func(int i, string &s){
        if(i == s.length()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j = i ; j < s.length() ; j++){
            if(isPal[i][j]){
                ans = min(ans, 1 + func(j+1, s));
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        constructIsPal(s);
        int n = s.length();
        if(isPal[0][n-1] == 1) return 0;
        return func(0, s)-1;
    }
};