class Solution {
public:
    string minWindow(string s, string t) {
        map <char, int> mp;
        int n = s.length(), m = t.length();
        if(n < m) return "";
        for(int i = 0 ; i < m ; i++) mp[t[i]]++;
        int l = 0, r = 0, cnt = 0, len = 1e9, si = -1;

        while(r < n){
            if(mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while(cnt == m){
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                if(r-l+1 < len){
                    len = r-l+1;
                    si = l;
                }
                l++;
            }
            r++;
        }   
        if(len == 1e9) return "";
        return s.substr(si, len);
    }
};