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
        if(s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return func(0, 0, s1, s2, s3);
    }
};