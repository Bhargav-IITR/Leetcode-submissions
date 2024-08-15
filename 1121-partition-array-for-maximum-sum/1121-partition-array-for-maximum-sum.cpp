class Solution {
public:
    int dp[505];
    int func(int i, vector <int> &a, int k){
        if(i == a.size()) return 0;
        if(dp[i] != -1) return dp[i]; 
        int ans = 0 ;
        int currMax = a[i], n = a.size();
        int r = min(i+k, n);
        for(int j = i ; j < r; j++){
            currMax = max(currMax, a[j]);
            int currSum = (j-i+1)*currMax;
            int next = func(j+1, a, k);
            ans = max(ans, currSum+next);
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return func(0, arr, k);
    }
};