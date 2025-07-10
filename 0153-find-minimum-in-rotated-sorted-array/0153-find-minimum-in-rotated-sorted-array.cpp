class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo < hi){
            int m = (lo+hi)>>1;
            if(nums[m] >= nums[0] && nums[m] > nums[n-1]) lo = m+1;
            else hi = m;
        }
        return nums[hi];
    }
};