class Solution {
public:
    int dp[505][505];
    int func(int i, int j, string &s, string &t){
        // insert -> 1 + func(i,j-1)
        // delete -> 1 + func(i-1,j)
        // replace -> 1 + func(i-1,j-1);
        if(i < 0) return j+1; //insrt
        if(j < 0) return i+1; //dlt
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return func(i-1,j-1,s,t);
        int ins = 1 + func(i,j-1,s,t);
        int dlt = 1 + func(i-1,j,s,t);
        int rpl = 1 + func(i-1,j-1,s,t);
        return dp[i][j] = min(ins, min(dlt, rpl));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        int n = word1.length(), m = word2.length();
        return func(n-1, m-1, word1, word2);
    }
}; 