class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        vector <vector<int>> pf(26, vector <int> (n, 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < 26 ; j++){
                pf[j][i] = (s[i]-'a' == j) +( (i == 0)?0 : pf[j][i-1]);
            }
        }
        int ans = 0;
        // generate all substrings and calculate for each
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int mx = INT_MIN, mn = INT_MAX; // max and min frequencies
                for(int k = 0 ; k < 26 ; k++){
                    int freqK = pf[k][j] - (i==0?0:pf[k][i-1]);
                    // if(freqK != 0){
                    //     mx = max(mx, freqK);
                    //     mn = min(mn, freqK);
                    // }
                    mx = max(mx, freqK);
                    mn = (freqK!=0)?min(freqK, mn):mn;
                }
                ans += (mx-mn);
            }
        }
        return ans;
    }
};