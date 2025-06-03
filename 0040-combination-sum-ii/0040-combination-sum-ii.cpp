class Solution {
public:
    vector <vector <int>> ans;
    void func(int id, vector <int> &temp, vector <int> &c, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        if(id == c.size()) return;
        //not take:
        int k = id;
        while(k < c.size() && c[k] == c[id]) k++;
        func(k, temp, c, target);
        //take:
        temp.push_back(c[id]);
        func(id+1, temp, c, target-c[id]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector <int> temp;
        sort(c.begin(), c.end());
        func(0, temp, c, target);
        return ans;
    }
};