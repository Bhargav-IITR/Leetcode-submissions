class Solution {
public: 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue <pair <string, int>> q;
        set <string> st;
        for(string s : wordList) st.insert(s);
        q.push({beginWord, 0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            string word = front.first;
            int d = front.second;
            if(word == endWord) return d+1;
            for(int i = 0 ; i < word.length() ; i++){
                for(char c = 'a' ; c <= 'z' ; c++){
                    if(c != word[i]){
                        string t = word;
                        t[i] = c;
                        if(st.find(t) != st.end()){
                            q.push({t, d+1});
                            st.erase(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};