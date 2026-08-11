class Solution {
public:
    int dp[(1<<12)][12];
    int dp2[(1<<12)][12];
    vector <vector <int>> overlap;
    
    int getOverlap(string &s1, string &s2){
        int n1 = s1.length();
        int n2 = s2.length();
         for(int len = min(n1, n2); len >= 1; len--) {
            if(s1.substr(n1 - len) == s2.substr(0, len)) {
                return len;
            }
        }

        return 0;
    }

    void calculateOverlap(vector <string> &words){
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                int cnt = getOverlap(words[i], words[j]);
                overlap[i][j] = cnt;
            }
        }
    }

    int getMinLen(int wordMask, int lastWord, vector <string> &words){
        if(wordMask == (1 << words.size()) - 1)
            return 0;
        if(dp[wordMask][lastWord] != -1) return dp[wordMask][lastWord];
        int ans = INT_MAX;
        int n = words.size();
        int next = -1;
        for(int i = 0 ; i < n ; i++){
            if(wordMask & (1<<i)) continue;
            int cost = words[i].length() - overlap[lastWord][i] + getMinLen(wordMask|(1<<i), i, words);
            if(cost < ans){
                ans = cost;
                next = i;
            }
        }
        dp2[wordMask][lastWord] = next;
        return dp[wordMask][lastWord] = ans;
    }

    string shortestSuperstring(vector<string>& words) {
        
        int n = words.size();
        overlap.resize(n, vector<int> (n, 0));
        calculateOverlap(words);
        memset(dp, -1 , sizeof(dp));
        memset(dp2, -1 , sizeof(dp2));

        int minLen = INT_MAX;
        int start = -1;
        for(int i = 0; i< n ;i++){
            int cost = words[i].length() + getMinLen(1<<i, i, words);
            if(cost < minLen){
                minLen = cost;
                start = i;
            }
        }

        int wordMask = 1 << start, last = start;
        string ans = words[last];
        while(wordMask != (1<<n)-1){
            int next = dp2[wordMask][last];
            int ov = overlap[last][next];
            ans += words[next].substr(ov);
            wordMask |= (1<<next);
            last = next;
        }
        return ans;
    }
};