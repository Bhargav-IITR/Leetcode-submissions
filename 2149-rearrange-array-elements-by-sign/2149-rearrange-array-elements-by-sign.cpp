class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1;
        vector <int> ans(nums.size());
        for(auto it : nums){
            if(it < 0){
                ans[j] = it;
                j += 2;
            }else{
                ans[i] = it;
                i += 2;
            }
        }
        return ans;
    }
};