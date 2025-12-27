class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector <int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++){
            int prevEnd = (ans.back())[1];
            if(intervals[i][0] > prevEnd){
                ans.push_back(intervals[i]);
            }else{
                (ans.back())[1] = max(prevEnd, intervals[i][1]);
            }
        }
        return ans;
    }
};