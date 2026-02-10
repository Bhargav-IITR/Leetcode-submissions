class Solution {
public: 
    int dp[300002][2];
    int func(int i, int buy, vector <int> &p){
        int n = p.size();
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int ans;
        if(buy){
            ans = max((i < n-1) ?(func(i+1, 0, p) - p[i]) : 0 , func(i+1, 1, p));
        }else{
            ans = max(func(i+1, 1, p) + p[i], func(i+1, 0, p));
        }
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        int ans = func(0, 1, prices);      
        if(ans < 0) return 0;
        return ans;
    }
};