class Solution {
public:
    unordered_set<string> dict;
    vector<int> dp;      // -1 = unvisited, 0 = false, 1 = true
    int n;

    bool func(int i, string &w) {
        if (i == n)
            return true;

        if (dp[i] != -1)
            return dp[i];

        string curr = "";
        for (int j = i; j < n; j++) {
            curr += w[j];

            if (dict.count(curr)) {
                if (func(j + 1, w))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s) {
        n = s.size();

        dp.assign(n, -1);

        return func(0, s);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string word : words){
            dict.insert(word);
        }
        vector <string> ans;
        for(string &word : words){
            dict.erase(word);
            bool flag = wordBreak(word);
            if(flag){
                ans.push_back(word);
            }
            dict.insert(word);
        }
        return ans;
    }
};