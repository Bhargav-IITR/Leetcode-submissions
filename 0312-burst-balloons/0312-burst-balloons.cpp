class Solution {
public:
    int dp[305][305];
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, 0, sizeof(dp));
        //return func(0, nums.size()-1, nums);
        int n = nums.size();
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = i+1 ; j < n ; j++){
                int ans = INT_MIN;
                for(int k = i+1 ; k < j ; k++){
                    ans = max(ans, nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
                }
                if(ans != INT_MIN) dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};