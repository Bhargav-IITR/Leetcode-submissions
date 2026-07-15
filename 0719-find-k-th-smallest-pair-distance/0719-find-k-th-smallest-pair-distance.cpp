class Solution {
public:
    int numLess(vector <int> &nums, int mid){
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ;i < n ; i++){
            int numj = nums[i] + mid;
            int j = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), numj)) - 1; // last index so that nums[j] - nums[i] <= mid
            ans += (j-i);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        sort(nums.begin(), nums.end());
        int lo = INT_MAX , hi = nums[n-1]-nums[0];
        for(int i = 0 ;i < n-1 ; i++) lo = min(lo, nums[i+1] - nums[i]);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (numLess(nums, mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};