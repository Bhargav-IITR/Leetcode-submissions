class Solution {
public:

    int dp[304][304];
    int func(int i, int j, vector <int> &nums){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int k = i ; k <= j ; k++){
            int t = nums[i-1]*nums[k]*nums[j+1] + func(i, k-1, nums) + func(k+1, j, nums);
            ans = max(ans, t);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return func(1,n,nums);
    }
};