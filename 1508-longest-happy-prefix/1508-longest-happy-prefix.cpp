class Solution {
public:
    vector<int> setupLPS(string &s) {
        int n = s.length();
        vector<int> lps(n); // Initialize LPS array
        lps[0] = 0; // The first LPS value is always 0
        int prevlps = 0; // Length of the previous longest prefix suffix
        int i = 1; // Start from the second character

        while (i < n) {
            if (s[i] == s[prevlps]) {
                lps[i] = prevlps + 1;
                prevlps++;
                i++;
            } else {
                if (prevlps == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prevlps = lps[prevlps - 1];
                }
            }
        }
        return lps; // Correctly return the LPS array
    }
    string longestPrefix(string s) {
        vector <int> lps = setupLPS(s);
        string ans = "";
        for(int i = 0 ; i < lps[s.length()-1] ; i++) ans += s[i];
        return ans;
    }
};