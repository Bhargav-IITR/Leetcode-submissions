class Solution {
public:
    #define ll long long

    int numberOfSubstrings(string s) {
        map <char, int> mp;
        // approach - total substrings -not all three together at the same time

        // calculate not all three together at the same time using 2 pointers:
        int l =0, r=0, n= s.length();
        int ans = 0;
        while(r < n){
            mp[s[r]]++;
            while(l < r && mp.size() == 3){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        int totalSubstrings = (int)(n*1ll*(n+1)/2);
        return totalSubstrings - ans;
    }
};