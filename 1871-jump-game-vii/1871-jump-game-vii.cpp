class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int n= s.length();
        vector <int> dp(n);
        if(s[n-1] == '1') return false;
        dp[0] = 1;
        vector <int> pf(n);
        pf[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(s[i] == '1'){
                dp[i] = 0;
            }
            else{
                int left = i-maxJump, right = i-minJump;
                if(right < 0) dp[i] = 0;
                else{
                    left = max(0, left), right = max(0, right);
                    int sum = pf[right] - ((left == 0 )? 0 : pf[left-1]);
                    if(sum > 0) {
                        dp[i] = 1;
                    }
                }
            }
            pf[i] = dp[i] + pf[i-1];
        }
        return dp[n-1];
    }
};