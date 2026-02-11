class Solution {
public:
    int dp[2501][2502];
    int func(vector <int> &nums, int i, int prev){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notTake = func(nums, i+1, prev);
        int take = 0;
        if(prev == -1 || (nums[prev] < nums[i])) take = 1 + func(nums, i+1, i);
        return dp[i][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return func(nums, 0, -1);
    }
};