class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        // for(int i = 1 ; i< n ; i += 3){
        //     //check left right
        //     if(nums[i-1] == nums[i+1]) continue;
        //     if(nums[i-1] == nums[i]) return nums[i+1];
        //     return nums[i-1];
        // }
        // return nums[n-1];
        int ans = 0;
        for(int i = 0; i <= 31 ; i++){
            int numSetBit = 0;
            for(int j = 0 ; j < n ; j++){
                if(nums[j]&(1<<i)) numSetBit++;
            }
            if((numSetBit%3) != 0) ans += (1<<i);
        }
        return ans;
    }
};