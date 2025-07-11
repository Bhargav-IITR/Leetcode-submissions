class Solution {
public:
    int dp[2][101][1001];

    int func(int buy, int k, int i, vector <int> &prices){
        if(k == 0) return 0;
        if(i == prices.size()) return 0;
        if(dp[buy][k][i] != -1) return dp[buy][k][i];
        if(buy){
            int op1 = -1*prices[i] + func(0, k, i+1, prices);
            int op2 = func(buy, k, i+1, prices);
            return dp[buy][k][i] = max(op1,op2);
        }else{
            int op1 = prices[i] + func(1, k-1, i+1, prices);
            int op2 = func(buy, k, i+1, prices);
            return dp[buy][k][i] = max(op1, op2);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return func(1,k,0, prices);
    }
};