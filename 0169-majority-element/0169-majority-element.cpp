class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, el;
        if(nums.size() == 1) return nums[0];
        for(auto it : nums){
            if(cnt == 0) el = it;
            if(it == el) cnt++;
            else cnt--;
        }
        return el;
    }
};