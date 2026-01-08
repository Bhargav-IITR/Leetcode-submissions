class Solution {
public:
    bool possible(vector <int> &nums, int cap, int k){
        int sum = 0;
        int students = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(sum + nums[i] <= cap){
                sum += nums[i];
            }else{
                sum = nums[i];
                students++;
            }
        }
        return (students <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        if(k > n) return -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(possible(nums, mid, k)){
                hi = mid-1;
            }else {
                lo = mid+1;
            }
        }
        return lo;
    }
};