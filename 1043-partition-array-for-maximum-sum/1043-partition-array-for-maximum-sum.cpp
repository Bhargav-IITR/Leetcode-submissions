class Solution {
public:
    int dp[505];
    int func(vector <int> &nums, int k, int i){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int temp = INT_MIN;
        for(int j = i ; j < i+k && j < n ; j++){
            temp = max(temp, nums[j]);
            ans = max(ans, (j-i+1)*temp + func(nums, k, j+1));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        
        return func(arr, k, 0);
    }
};