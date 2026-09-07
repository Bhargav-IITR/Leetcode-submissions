class Solution {
public:
    int integerBreak(int n) {
        int ans = INT_MIN;
        for(int i = 2 ; i <= n ; i++){
            int nums = n/i;
            // i numbers with each value - nums 
            int rem = n%i; 
            ans = max(ans, (int)pow(nums+1, rem)*(int)pow(nums, i-rem));
        }
        return ans;
    }
};