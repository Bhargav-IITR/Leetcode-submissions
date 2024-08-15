class Solution {
public:
    int dp[105][105];
    int func(int i, int j, vector <int> &cuts){
        if(j < i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i ; k <= j ; k++){
            int len = cuts[j+1]-cuts[i-1];
            int left = func(i,k-1, cuts);
            int right = func(k+1,j,cuts);
            ans = min(ans, len+left+right);
        }
        return dp[i][j] = ans;
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