class Solution {
public:
    // just did the first iteration to solve the prblm - o(n^2) - never will pass 
    // int func(int date, int id, vector <vector<int>> &c, vector<vector<int>> &dp, int maxEndDate, int n){
    //     if(date > maxEndDate) return 0;
    //     if(id >= n) return 0;
    //     if(dp[date][id] != -1) return dp[date][id];
    //     int notTake = func(date, id+1, c, dp, maxEndDate, n);
    //     int take = 0;
    //     if(date + c[id][0]-1 <= c[id][1]) take = 1 + func(date + c[id][0] , id+1, c, dp, maxEndDate, n);
    //     return dp[date][id] = max(take, notTake);
    // }

    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](const vector <int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        priority_queue <int> pq;
        int currEndDate = 0;   
        for(int i = 0; i< n; i++){
            if(currEndDate + courses[i][0] <= courses[i][1]){
                currEndDate += courses[i][0];
                pq.push(courses[i][0]);
            }else{
                if(!pq.empty() && (pq.top() > courses[i][0])){
                    currEndDate -= pq.top();
                    pq.pop();
                    pq.push(courses[i][0]);
                    currEndDate += courses[i][0];
                }
            }
        }
        return pq.size();
    }
};