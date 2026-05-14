class Solution {
public: 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <string> q;
        map <string, int> mp;
        for(string word : wordList) mp[word]++;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                string s = q.front();
                q.pop();
                if(s == endWord) return ans;
                for(int i = 0 ; i < s.length() ; i++){
                    for(char c = 'a' ; c <= 'z' ; c++){ 
                        char temp = s[i];
                        s[i] = c;
                        if(mp.find(s) != mp.end()){
                            q.push(s);
                            if(mp.find(s) != mp.end()) mp.erase(s);
                        }
                        s[i] = temp;
                    }
                }
            }
        }
        return 0;
    }
};