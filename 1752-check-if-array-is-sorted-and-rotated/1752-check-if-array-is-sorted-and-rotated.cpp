class Solution {
public:
    bool check(vector<int>& nums) {
        int ab = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] > nums[i+1]) ab++;
        }
        if(ab >= 2) return false;
        if(ab == 1){
            return nums[0] >= nums[nums.size()-1];
        }
        return true;
    }
};