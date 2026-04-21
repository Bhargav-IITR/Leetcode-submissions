class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        
        unordered_map<int, int> mp;
        vector<string> res;
        int hash = 0;
        
        unordered_map<char, int> val = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        };
        
        for(int i = 0; i < s.size(); i++) {
            hash = ((hash << 2) | val[s[i]]) & ((1 << 20) - 1);
            
            if(i >= 9) {
                mp[hash]++;
                if(mp[hash] == 2) {
                    res.push_back(s.substr(i - 9, 10));
                }
            }
        }
        return res;
    }
};