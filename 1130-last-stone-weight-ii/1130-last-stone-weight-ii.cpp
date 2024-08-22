class Solution {
public:
    int dp[35][3005];
    int func(int id, int w, vector<int> &s){
        if(id == s.size() || w == 0) return 0;
        if(dp[id][w] != -1) return dp[id][w];
        int take = 0, notTake = 0;
        notTake = func(id+1,w,s);
        if(w >= s[id]) take = s[id] + func(id+1,w-s[id], s);
        return dp[id][w] = max(take,notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto it : stones) sum += it;
        memset(dp, -1, sizeof(dp));
        int pos = func(0,sum/2,stones);
        return (sum-2*pos);
    }
};