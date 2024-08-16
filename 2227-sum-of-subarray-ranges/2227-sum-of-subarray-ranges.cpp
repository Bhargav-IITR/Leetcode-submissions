#define ll long long
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> minmax(n,vector<pair<int,int>>(n));
        for(int i = 0 ; i < n ; i++){
            minmax[i][i] = {nums[i], nums[i]};
        }
        for(int i = 0 ; i < n-1 ; i++){
            minmax[i][i+1] = {min(nums[i], nums[i+1]), max(nums[i], nums[i+1])};
        }
        for(int len = 3 ; len <= n ; len++){
            for(int i = 0 ; i < n ; i++){
                int j = i+len-1;
                if(j < n){
                    int mx = max(nums[i], minmax[i+1][j].second);
                    int mn = min(nums[i], minmax[i+1][j].first);
                    minmax[i][j] = {mn, mx};
                }
            }
        }
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                ans += 1l*(minmax[i][j].second-minmax[i][j].first);
            }
        }
        return ans;
    }
};