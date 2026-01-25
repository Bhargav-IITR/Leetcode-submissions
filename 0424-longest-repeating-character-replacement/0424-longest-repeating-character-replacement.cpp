class Solution {
public:
    int mf(int l, int r, vector <vector <int>> &pf, string &s){
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            int freq =pf[i][r+1]-pf[i][l];
            if(freq != 0) ans = max(ans, freq);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector <vector<int>> pf(26, vector <int> (n+1, 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 26 ; j++){
                pf[j][i+1] = pf[j][i] + (j == (s[i]-'A'));
            }
        }
        int l = 0, r = 0, ans = 0;
        while(r < n){
            while((l < r) && ((r-l+1) - mf(l,r,pf,s) > k)){
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};