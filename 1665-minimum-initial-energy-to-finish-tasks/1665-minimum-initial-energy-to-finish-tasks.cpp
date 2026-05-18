class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b){
            return a[1]-a[0] > b[1]-b[0];
        });
        //decreasing order of gap
        int ans = 0, rem = 0;
        for(auto it : tasks){
            int mini = it[1], actual = it[0];
            if(rem < mini){
                ans += (mini-rem);
                rem = mini;
            }
            rem -= actual;
        }
        return ans;
    }
};