class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; i++){
            int new_start = intervals[i][0], new_end = intervals[i][1];
            if(new_start > end){
                ans.push_back({start , end});
                start = new_start , end = new_end;
            }
            else{
                end = max(end, new_end);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};