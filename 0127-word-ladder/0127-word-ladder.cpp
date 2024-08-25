class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set <string> st;
        for(auto it : wordList) st.insert(it);
        queue <pair<string,int>> q;
        q.push({beginWord, 0});
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            string word = f.first;
            int d = f.second;
            if(word == endWord) return d+1;
            for(int i = 0 ; i < word.length();i++){
                for(char c = 'a' ; c <= 'z' ; c++){
                    if(c != word[i]){
                        string newWord = word;
                        newWord[i] = c;
                        if(st.find(newWord)!=st.end()){
                            q.push({newWord, d+1});
                            st.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};