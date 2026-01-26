class Solution {
public:
    int maxK(vector <int> &nums, int k){
        int l = 0, r = 0, n = nums.size();
        int ans = 0;
        map <int, int> mp;
        while(r < n){
            mp[nums[r]]++;
            while(l < r && mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            if(k != 0) ans += (r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return maxK(nums, k) - maxK(nums, k-1);
    }
};