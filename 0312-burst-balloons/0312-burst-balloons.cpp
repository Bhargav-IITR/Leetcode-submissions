class Solution {
public:
    int dp[305][305];
    int func(int i , int j, vector <int> &nums){
        if(i > j) return 0;
        if(dp[i+1][j+1] != -1) return dp[i+1][j+1];
        int ans = 0;
        for(int k = i+1 ; k < j ; k++){
            int l = (i == -1) ? 1 : nums[i];
            int r = (j == nums.size()) ? 1 : nums[j];
            int t = l*r*nums[k];
            ans = max(ans, func(i, k, nums) + func(k, j, nums) + t);
        }
        return dp[i+1][j+1] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return func(-1, nums.size(), nums);
    }

};