class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int n = nums.size();
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target) return true;
            if(nums[lo] == nums[mid]){
                lo++;
                continue;
            }
            if(nums[lo] <= nums[mid]){
                //left part sorted
                if(nums[lo] <= target && target <= nums[mid]) hi = mid-1;
                else lo = mid+1;
            }
            else{
                if(nums[mid] <= target && target <= nums[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};