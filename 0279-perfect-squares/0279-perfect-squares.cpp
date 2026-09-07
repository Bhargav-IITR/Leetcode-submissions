class Solution {
public:
#define ll long long 
    ll dp[101][10001];
    ll minSum(int id, int left){
        if(left == 0) return 0;
        if(id*id > left) return INT_MAX;
        if(dp[id][left] != -1) return dp[id][left];
        ll notTake = minSum(id+1, left);
        ll take = 1 + minSum(id+1, left-(id*id));
        return dp[id][left] = min(take, notTake);
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        ll ans = minSum(1, n);
        return (int)ans;
    }
};