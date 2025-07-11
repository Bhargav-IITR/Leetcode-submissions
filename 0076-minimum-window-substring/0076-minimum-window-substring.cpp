class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";
        map <char, int> mp;
        for(int i = 0 ; i < n ; i++) mp[t[i]]++;
        int l = 0, r = 0, cnt = 0;
        int len = INT_MAX, start = -1;
        while(r < m){
            if(mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while(cnt == n){
                if(r-l+1 < len){
                    len = r-l+1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(start == -1) return "";
        return s.substr(start, len);        
    }
};