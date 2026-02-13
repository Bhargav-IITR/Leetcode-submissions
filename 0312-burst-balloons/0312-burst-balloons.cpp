class Solution {
public:
    int dp[305][305];
    int func(int i, int j, vector <int> &nums){
        if(j-i == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k = i+1 ; k < j ; k++){
            ans = max(ans, nums[i]*nums[k]*nums[j] + func(i, k, nums) + func(k, j, nums));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return func(0, nums.size()-1, nums);
    }
};