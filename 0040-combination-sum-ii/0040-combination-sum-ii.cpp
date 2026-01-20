class Solution {
public:
    vector <vector <int>> ans;
    void func(int i, vector <int> &c, int target, vector <int> tmp){
        int n = c.size();
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        if(i == n) return;
        if(c[i] <= target){
            tmp.push_back(c[i]);
            func(i+1, c, target-c[i], tmp);
            tmp.pop_back();
        }
        while(i+1 < n && (c[i] == c[i+1])) i++;
        func(i+1, c, target, tmp);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector <int> tmp;
        func(0, c, target, tmp);
        return ans;
    }
};