class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int i = 0;
        vector <pair <int, int>> vp;
        int start = 0;
        while(i < n){
            int numi = nums[i];
            int numj = nums[i] + maxDiff;
            int j = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), numj)) - 1;
            if(j == i){
                vp.push_back({start, j});
                start = i+1;
                i++;
            }
            else i = j;
        }
        vector <int> v(n, -1);
        for(int j = 0 ; j < vp.size() ; j++){
            auto p = vp[j];
            int start = p.first , end = p.second;
            for(int k = start ; k <= end ; k++) v[k] = j;
        }
        vector <bool> ans;
        for(auto query : queries){
            int ui = query[0], vi = query[1];
            if(v[ui] == v[vi]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};