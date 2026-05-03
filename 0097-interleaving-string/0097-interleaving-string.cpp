class Solution {
public:
    int dp[105][105];
    bool func(int i1, int i2, string &s1, string &s2, string &s3){
        int j = (i1+i2);
        int n = s1.length(), m = s2.length(), l = s3.length();
        if(j == l) return true;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        // 3 cases - 
        // check s1[i1] == s3[j] && s2[i2] != s3[j] -> take s1
        // s1[i1] != s3[j] && s2[i2] == s3[j] -> take s2
        // s1[i1] == s2[i2] == s3[j] -> take both cases
        // else return false if no match
        bool ans;
        if((s1[i1] == s3[j]) && (s2[i2] != s3[j])) ans = func(i1+1, i2, s1,s2,s3);
        else if((s1[i1] != s3[j]) && (s2[i2] == s3[j])) ans = func(i1, i2+1, s1,s2,s3);
        else if((s1[i1] == s3[j]) && (s2[i2] == s3[j])) ans = func(i1+1, i2, s1,s2,s3)|func(i1, i2+1, s1,s2,s3);
        else ans = false;
        return dp[i1][i2] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        if(n + m != s3.length()) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        dp[n][m] = true;
        for(int i = n ; i >= 0 ; i--){
            for(int j = m ; j >= 0 ; j--){
                if(i < n && s1[i] == s3[i + j]) {
                    dp[i][j] = dp[i][j] || dp[i + 1][j];
                }

                if(j < m && s2[j] == s3[i + j]) {
                    dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};