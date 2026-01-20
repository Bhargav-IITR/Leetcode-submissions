class Solution {
public:
    vector <vector <int>> ans;
    void func(int i, vector <int> &c, int target, vector <int> temp){
        int n = c.size();
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i == n) return;
        //take: 
        if(c[i] <= target){
            temp.push_back(c[i]);
            func(i, c, target-c[i], temp); // no incriment i to allow repeated element
            temp.pop_back();
        }
        //not take
        func(i+1, c, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> temp;
        func(0, candidates, target, temp);
        return ans;
    }
};