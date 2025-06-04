class Solution {
public:
    pair <int,int> pal(string &s, int i, int j){
        while(i>= 0 && j < s.length() && s[i]==s[j]) i--,j++;
        return {i+1,j-1};
    }
    string longestPalindrome(string s) {
        int ml = 1;
        pair <int, int> m;
        for(int i = 0 ; i < s.length() ; i++){
            pair <int, int> p1 = pal(s, i,i);
            pair <int, int> p2 = pal(s,i,i+1);
            int odd = p1.second-p1.first+1;
            int even = p2.second-p2.first+1;
            if(max(odd,even) > ml){
                ml = max(odd,even);
                if(odd > even) m = p1;
                else m = p2;
            }
        }
        string ans = "";
        for(int i = m.first ; i <= m.second ; i++) ans += s[i];
        return ans;
    }
};