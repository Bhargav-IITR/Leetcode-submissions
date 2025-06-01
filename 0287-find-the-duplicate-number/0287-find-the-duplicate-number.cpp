class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int lo = 1, hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            int cnt = 0;
            for(auto e : nums) if(e <= mid) cnt++;
            if(cnt <= mid) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};