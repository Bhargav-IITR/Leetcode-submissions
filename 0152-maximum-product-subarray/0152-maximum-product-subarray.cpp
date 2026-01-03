class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector <int> pf(n, INT_MIN), sf(n, INT_MIN);
        bool zeroFlag = false;
        int p = 1;
        for(int i = 0 ; i < n ; i++){
            p *= nums[i];
            if(p == 0) pf[i] = INT_MIN, p = 1, zeroFlag = true;
            else pf[i] = p;
        }
        p = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            p *= nums[i];
            if(p == 0) sf[i] = INT_MIN, p = 1;
            else sf[i] = p;
        }
        int ans = pf[n-1];
        if(n == 1) return nums[0];
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                ans = max(ans, sf[1]);
            }else if(i == n-1){
                ans = max(ans, pf[n-2]);
            }else{
                ans = max(ans, max(pf[i-1], sf[i+1]));
            }
        }
        if(ans < 0 && zeroFlag) return 0;
        return ans;
    }
};