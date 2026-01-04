class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        if(hi == 0) return nums[0];
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(mid&1){ //odd index
                if(nums[mid] == nums[mid-1]) lo = mid+1;
                else hi = mid-1;
            }else{ //even index
                if(mid != nums.size()-1 && nums[mid] != nums[mid+1]) hi = mid;
                else lo = mid+1;
            }
        }
        return nums[hi];
    }
};