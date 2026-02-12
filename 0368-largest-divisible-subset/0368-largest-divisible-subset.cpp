class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector <int> DP(n,1); 
        //DP[i] = maximum length of LDS ending at index i
        vector <int> pre(n);
        int lis = -1;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            pre[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if((nums[i]%nums[prev] == 0) && DP[i] < 1 + DP[prev]){
                    DP[i] = 1 + DP[prev];
                    pre[i] = prev;
                }
            }
            if(ans < DP[i]){
                ans = DP[i];
                lis = i;
            }
        }
        vector <int> fin;
        while(pre[lis] != lis){
            fin.push_back(nums[lis]);
            lis = pre[lis];
        }
        fin.push_back(nums[lis]);
        reverse(fin.begin(), fin.end());
        return fin;
    }
};