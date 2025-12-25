class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i < 0){
            sort(nums.begin(), nums.end());
            return;
        }
        sort(nums.begin() + i + 1, nums.end());
        int j = distance(nums.begin(), upper_bound(nums.begin() + i + 1, nums.end(), nums[i]));
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
    }
};