class Solution {
public:
    int dp[50001];
    int func(int i, vector <pair <int, pair<int,int>>> &v){
        if(i == v.size()) return 0;
        if(dp[i] != -1) return dp[i];
        //notTake:
        int notTake = func(i+1, v);
        //take:
        //calculate the first interval whose start time is greater than endtrime[i]
        int j = i+1;
        for( ; j < v.size() ; j++){
            if(v[j].first >= v[i].second.first) break;
        }
        int take = v[i].second.second + func(j, v);
        int ans = max(take, notTake);
        return dp[i] = ans;        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector <pair <int, pair<int,int>>> v;
        for(int i= 0 ; i < n ; i++){
            v.push_back({startTime[i], {endTime[i], profit[i]}});
        }
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        return func(0, v);
    }
};