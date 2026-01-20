class Solution {
public:
    void func(int i, vector <vector <int>> &ans, vector <int> &temp, vector <int> &nums){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(i+1, ans, temp, nums);
        temp.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i+1])i++;
        func(i+1, ans, temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> temp;
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans;
        func(0, ans, temp, nums);
        return ans;
    }
};