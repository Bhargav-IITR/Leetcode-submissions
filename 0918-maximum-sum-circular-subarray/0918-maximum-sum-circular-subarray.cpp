class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // first find max sum using kadane normal : 
        int sum1 = INT_MIN, sum2 = INT_MAX;
        int curr1 = 0, curr2 = 0;
        int totalSum = 0;
        for(int i = 0 ;i < n ; i++){
            totalSum += nums[i];
            // normal kadane - 
            curr1 += nums[i];
            sum1 = max(sum1, curr1);
            if(curr1 < 0) curr1 = 0;

            // now min sum- 
            curr2 += nums[i];
            sum2 = min(sum2, curr2);
            if(curr2 > 0) curr2 = 0;
        }
        if(sum1 < 0) return sum1;
        return max(sum1, totalSum - sum2);
    }
};