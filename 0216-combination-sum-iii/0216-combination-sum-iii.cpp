class Solution {
public:
    vector<vector<int>> ans;
    void func(int i, int k, int n, vector <int> &temp){
        if(k == 0){
            if(n == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(i == 10) return;
        temp.push_back(i);
        func(i+1, k-1, n-i, temp);
        temp.pop_back();
        func(i+1,k,n,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> tmp;
        func(1, k, n, tmp);
        return ans;
    }
};