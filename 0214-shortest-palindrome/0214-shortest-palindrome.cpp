class Solution {
public:
    int M = 1e9+7;
    #define ll long long
    //use rabin karp hashing algorihtm to find the largest prefix pallindrome
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int lp = -1, n = s.length();
        ll power = 1;
        ll h1 = 0, h2 = 0;
        for(int i = 0 ; i < n ; i++){
            h1 = (h1*29 + s[i]-'a'+1)%M;
            int j = n-i-1;
            h2 = (h2 + power*(t[j]-'a'+1))%M;
            if(h1 == h2) lp = i;
            power = (power*29)%M;
        }

        t = "";
        for(int i = lp+1 ; i < n ; i++) t += s[i];
        reverse(t.begin(), t.end());
        t = t + s;
        return t;
    }
};