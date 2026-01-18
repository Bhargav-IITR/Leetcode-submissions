class Solution {
public:
    int beautySum(string s) {

        vector <vector <int>> pf(26, vector <int> (s.length(), 0));
        for(int i = 0; i < s.length() ;i++){
            for(int j = 0 ; j < 26 ; j++){
                if(i == 0) pf[j][i] = (j == s[i]-'a');
                else pf[j][i] += pf[j][i-1] + (j == s[i]-'a');
            }
        }

        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = i+1 ; j < s.length() ; j++){
                int mx = INT_MIN, mn = INT_MAX;
                for(int k = 0 ; k < 26 ; k++){
                    int l = (i == 0) ? 0:pf[k][i-1];
                    int r = pf[k][j];
                    int f = r-l;
                    mx = max(mx, f);
                    mn = (f != 0)?min(mn, f):mn;
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};