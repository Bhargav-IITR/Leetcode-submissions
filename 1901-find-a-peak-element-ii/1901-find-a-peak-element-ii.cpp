class Solution {
public:
    int maxInCol(vector <vector <int>> &a, int col){
        int id = 0, m = INT_MIN;
        for(int r = 0 ; r < a.size() ; r++){
            if(a[r][col] > m){
                id = r;
                m = a[r][col];
            }
        }
        return id;
    }
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int lo = 0 , hi = nums[0].size();
        int n = nums[0].size();
        while(lo <= hi){
            int c = (lo+hi)/2;
            int r = maxInCol(nums, c);
            if((c == 0 || nums[r][c]>nums[r][c-1]) && (c == n-1 || nums[r][c]>nums[r][c+1])){
                return {r,c};
            }
            else if((c == 0 || nums[r][c]>nums[r][c-1]) && (c != n-1 && nums[r][c] < nums[r][c+1])){
                lo = c+1;
            }
            else if((c != 0 && nums[r][c] < nums[r][c-1]) && (c == n-1 || nums[r][c]>nums[r][c+1])){
                hi = c-1;
            }
            else hi = c-1;
        }
        return {};
    }
};