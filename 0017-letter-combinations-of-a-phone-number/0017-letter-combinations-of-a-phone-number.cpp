class Solution {
public:
    void func(int i , string &s, string t, vector <string> &ans, map <char, string> &mp){
        int n = s.length();
        if(i == n){
            ans.push_back(t);
            return;
        }
        string k = mp[s[i]];
        for(auto it: k){
            func(i+1, s, t + it, ans, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        map <char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector <string> ans;
        string t = "";
        func(0, digits, t, ans, mp);
        return ans;
    }
};