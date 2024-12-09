class Solution {
public:
    vector<vector<int>> ans;
    void func(int i, int target, vector <int> &c, vector <int> &temp){
        if(0 == target){
            ans.push_back(temp);
            return;
        }
        int n = c.size();
        if(i == n) return;
        for(int j = i ; j < n ; j++){
            if(j != i && c[j] == c[j-1]) continue;
            if(target < c[j]) break;
            temp.push_back(c[j]);
            func(i+1, target-c[j], c, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <int> temp;
        func(0, target, candidates, temp);
        return ans;
    }
};