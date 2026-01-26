class Solution {
public:
    int maxK(vector <int> &nums, int k){
        int l = 0, r =0, n = nums.size();
        int ans = 0, numOdd = 0;
        while(r < n){
            numOdd += (nums[r]&2 != 0);
            while(l < r && numOdd > k){
                numOdd -= (nums[l]%2 != 0);
                l++;
            }
            if(!(l == r && nums[l]%2 != 0 && k == 0)) ans += (r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return maxK(nums, k)-maxK(nums, k-1);
    }
};