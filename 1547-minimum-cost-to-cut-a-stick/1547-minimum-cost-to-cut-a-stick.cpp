class Solution {
public:
    int dp[102][102];
    int func(int i, int j, vector <int> &cuts){
        if(j-i == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1 ; k < j ; k++){
            ans = min(ans, cuts[j]-cuts[i] + func(i, k, cuts) + func(k, j, cuts));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        memset(dp, -1, sizeof(dp));
        return func(0, cuts.size()-1, cuts);
    }
};