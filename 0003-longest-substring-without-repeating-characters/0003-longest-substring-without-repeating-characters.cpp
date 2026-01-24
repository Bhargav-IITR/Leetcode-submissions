class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> mp;
        int l = 0, r = 0;
        int n = s.length();
        if(n == 1) return 1;
        int ans = 0;
        while(r< n){
            mp[s[r]]++;
            if(mp[s[r]] == 2){
                ans = max(ans , r-l);
                while(s[l] != s[r]){
                    mp[s[l]]--;
                    l++;
                }
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        ans = max(ans, r-l);
        return ans;
    }
};