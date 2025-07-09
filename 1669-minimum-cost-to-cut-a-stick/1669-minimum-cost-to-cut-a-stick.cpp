class Solution {
public:
    int dp[105][105];
    int func(int i, int j, vector <int> &cuts){
        if(i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cost = INT_MAX;
        for(int k = i ; k <= j ; k++){
            int x = cuts[j+1]-cuts[i-1] + func(i, k-1, cuts) + func(k+1, j, cuts);
            cost = min(cost, x);
        }
        return dp[i][j] = cost;
    }

    int minCost(int n, vector<int>& cuts) {  
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(), cuts.end());
        int N = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return func(1,N,cuts);
    }
};