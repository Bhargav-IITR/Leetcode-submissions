class Solution {
public:
    pair <int, int> dp[101][101][2][102];

    pair <int, int> func(int i, int j, int turn, int m, vector <int> &piles){
        if(i > j) return {0,0};
        if(dp[i][j][turn][m] != make_pair(-1,-1)) return dp[i][j][turn][m];
        int sum = 0;
        int X = 2*m;
        int maxi = INT_MIN;
        pair <int, int> ans = {-1, -1};
        for(int k = i ; k <= min(i+X-1, j) ; k++){
            sum += piles[k];
            auto p = func(k+1, j, turn^1, max(m, k-i+1), piles);
            if(turn){ // alice
                if(sum + p.first > maxi){
                    ans = make_pair(sum + p.first, p.second);
                    maxi = sum + p.first;
                }
            }else{
                if(sum + p.second > maxi){
                    ans = make_pair(p.first, sum + p.second);
                    maxi = sum + p.second;
                }
            }
        } 
        return dp[i][j][turn][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        pair <int, int> ans = func(0, n-1, 1, 1, piles);
        return ans.first;
    }
};