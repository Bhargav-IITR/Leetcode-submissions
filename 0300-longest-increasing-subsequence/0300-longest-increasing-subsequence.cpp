class Solution {
public:
    int dp[2502][2502];
    int func(vector <int> &nums, int i, int prev){
        int n = nums.size();
        if(i < 0) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int notTake = func(nums, i-1, prev);
        int take = 0;
        if(prev == n || (nums[prev] > nums[i])) take = 1 + func(nums, i-1, i);
        return dp[i][prev] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        // return func(nums, nums.size()-1, nums.size());
        int n = nums.size();
        // vector <vector <int>> dp(n+1, vector <int> (n+1, -1));
        // for(int j = 0 ; j <= n ; j++) dp[0][j] = 0;
        // for(int i = 1 ; i <= n ; i++){
        //     for(int prev = i ; prev <= n ; prev++){
        //         int notTake = dp[i-1][prev];
        //         int take =0 ;
        //         if(prev == n || nums[prev] > nums[i-1]) take = 1 + dp[i-1][i-1];
        //         dp[i][prev] = max(take, notTake);
        //     }
        // }
        // return dp[n][n];
        // most optimal solution -
        vector <int> tails;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int tailSize = tails.size();
            int id = distance(tails.begin(), lower_bound(tails.begin(), tails.end(), nums[i]));
            if(id == tailSize){
                tails.push_back(nums[i]);
                ans = max(ans, tailSize+1);
            }else{
                tails[id] = nums[i];
            }
        }
        return ans;
    }
};