class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int i = 0;
        vector <int> v(n, -1);
        int start = 0, comp = 0;
        while(i < n){
            int numi = nums[i];
            int numj = nums[i] + maxDiff;
            int j = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), numj)) - 1;
            if(j == i){
                // vp.push_back({start, j});
                v[start] = comp;
                v[j] = comp;
                start = i+1;
                i++;
                comp++;
            }
            else i = j;
        }
        
        // for(int j = 0 ; j < vp.size() ; j++){
        //     auto p = vp[j];
        //     int start = p.first , end = p.second;
        //     for(int k = start ; k <= end ; k++) v[k] = j;
        // }
        for (int i = 0; i < n; ) {
            if (v[i] == -1) {
                i++;
                continue;
            }

            int j = i + 1;
            while (j < n && v[j] == -1) {
                j++;
            }

            if (j < n && v[j] == v[i]) {
                for (int k = i + 1; k < j; k++) {
                    v[k] = v[i];
                }
            }

            i = j;
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