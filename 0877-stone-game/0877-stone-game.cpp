class Solution {
public:
    pair <int, int> dp[501][501][3];
    pair <int, int> func(int i, int j, int turn , vector <int> &piles){
        if(i > j) return {0,0};
        if(dp[i][j][turn] != make_pair(-1,-1)) return dp[i][j][turn];
        auto op1 = func(i+1, j, turn^1, piles);
        auto op2 = func(i, j-1, turn^1, piles);
        pair<int, int> ans;
        if(turn){ // alice
            if(piles[i] + op1.first > piles[j] + op2.first) ans = make_pair(piles[i] + op1.first, op1.second);
            else ans = make_pair(op2.first + piles[j] , op2.second);
        }else{ // bob
            if(piles[i] + op1.second > piles[j] + op2.second ) ans = make_pair(op1.first , piles[i] + op1.second);
            else ans = make_pair(op2.first, piles[j] + op2.second);
        }
        return dp[i][j][turn] = ans;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        auto ans = func(0, n-1, 1, piles);
        return ans.first > ans.second;
    }
};