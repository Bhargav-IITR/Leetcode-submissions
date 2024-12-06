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

    int strStr(string haystack, string needle) {
        vector <int> lps = setupLPS(needle);
        int i = 0, j = 0;
        while(i < haystack.length()){
            if(haystack[i] == needle[j]){
                i++,j++;
            }
            else{
                if(j == 0) i++;
                else j = lps[j-1];
            }
            if(j == needle.length()) return i-needle.length();
        }
        return -1;
    }
};