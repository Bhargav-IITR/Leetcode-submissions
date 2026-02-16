class Solution {
public: 
    int dp[2001][2001];
    #define ll long long 
    vector <vector <int>> pal(string &s){
        int n = s.length();
        vector <vector <int>> ans(n, vector <int> (n, 0));
        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i < n ; i++){
                int j = i+len-1;
                if(j<n){
                    if(i == j) ans[i][j] = 1;
                    else if(j-i == 1) ans[i][j] = (s[i] == s[j]);
                    else{
                        ans[i][j] = ((s[i] == s[j]) & (ans[i+1][j-1] == 1));
                    }
                }
            }
        }
        return ans;
    }
    ll func(string &s, int i, int j, vector <vector<int>> &p){
        if(i >= j) return 0;
        if(p[i][j]) return 0;   // key fix
        if(dp[i][j] != -1) return (ll)dp[i][j];
        ll ans = INT_MAX;
        for(int k = i ; k <= j ; k++){
            if(p[i][k] == 1){
                ans = min(ans, 1 + func(s, k+1, j, p));
            }
        }
        dp[i][j] = (int)((ans >= INT_MAX) ? INT_MAX:ans);
        return (ll)dp[i][j];
    }
    int minCut(string s) {
        vector <vector <int>> p = pal(s);
        memset(dp, -1, sizeof(dp));
        if(p[0][s.length()-1] == 1) return 0;
        int ans = func(s, 0, s.length()-1, p);
        return ans;
    }
};