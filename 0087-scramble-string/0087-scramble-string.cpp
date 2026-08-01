class Solution {
public: 

    int dp[31][31][31][31];

    bool func(int i1, int j1, int i2, int j2, string &s1, string &s2){
        if(j1 == i1) return (s1[i1] == s2[i2]);
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

        //optmisation - check if character frequency matches for scramble : 
        vector <int> v(26, 0);
        for(int i = i1 ; i <= j1 ; i++) v[s1[i]-'a']++;
        for(int i = i2 ; i <= j2 ; i++) v[s2[i]-'a']--;

        for(int i = 0 ; i <26 ; i++) if(v[i] != 0) return dp[i1][j1][i2][j2] = false;

        for(int k = i1 ; k < j1 ; k++){
            int lenLeft = k - i1 + 1;
            int lenRight = j1 - k;
            bool op1 = func(i1,k,i2, i2+lenLeft-1, s1, s2) && func(k+1, j1, i2+lenLeft, j2, s1, s2);
            bool op2 = func(i1, k , j2-lenLeft+1, j2, s1, s2) && func(k+1, j1, i2, j2-lenLeft, s1, s2);
            if(op1||op2) return dp[i1][j1][i2][j2] = true;
        }
        return dp[i1][j1][i2][j2] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.length();
        memset(dp, -1, sizeof(dp));
        return func(0, n-1, 0, n-1, s1, s2);
    }
}; 