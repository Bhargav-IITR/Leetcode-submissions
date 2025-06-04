class Solution {
public:
    vector<int> setupLPS(string &s) {
        int n = s.length();
        vector <int> pi(n, 0);
        for(int i = 1 ; i < n ; i++){
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]) j = pi[j-1];
            if(s[j] == s[i]) j++;
            pi[i] = j;
        }
        return pi;
    }

    int strStr(string haystack, string needle) {
        vector <int> lps = setupLPS(needle);
        int i = 0, j = 0;
        while(i < haystack.length()){
            if(haystack[i] == needle[j]){
                i++,j++;
            }else{
                if(j != 0) j = lps[j-1];
                else i++;
            }
            if(j == needle.length()) return i-j;
        }
        return -1;
    }
};