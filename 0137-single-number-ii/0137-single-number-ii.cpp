class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1 ; i< n ; i += 3){
            //check left right
            if(nums[i-1] == nums[i+1]) continue;
            if(nums[i-1] == nums[i]) return nums[i+1];
            return nums[i-1];
        }
        return nums[n-1];
    }
};