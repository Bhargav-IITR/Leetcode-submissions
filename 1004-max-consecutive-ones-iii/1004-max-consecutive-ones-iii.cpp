class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        int z =0 ;
        int n = nums.size();
        while(r < n){
            if(nums[r] == 0) z++;
            if(z > k){
                while(z > k && l < r){
                    if(nums[l] == 0) z--;
                    l++;
                }
            }
            int len = r-l+1;
            if(!(len == 1 && k == 0 && nums[r] == 0))ans = max(ans, len);
            r++;
        }
        return ans;
    }
};