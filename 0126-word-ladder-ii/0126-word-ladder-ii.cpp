class Solution {
public:
unordered_map <string, int> mp;
vector <vector <string>> ans;
string b;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& list) {
        set <string> st(list.begin(), list.end());
        queue <string> q;
        q.push(beginWord);
        st.erase(beginWord);
        b = beginWord;
        int sz = b.size();
        mp[beginWord] = 0;
        int mn = INT_MAX;
        while(!q.empty()){
            string word = q.front();
            q.pop();
            int lvl = mp[word];
            if(word == endWord){
                break;
            }
            for(int i = 0 ; i < sz ; i++){
                char ch = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mp[word] = lvl+1;
                    }
                }
                word[i] = ch;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }      
        return ans;
    }
    void dfs(string word, vector <string> &seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = mp[word];
        for(int i =0 ; i< word.size() ;i++){
            char ch = word[i];
            for(char c = 'a' ; c <= 'z' ; c++){
                word[i] = c;
                if((mp.find(word) != mp.end()) && (mp[word] == step-1)){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = ch;
        }
    }
};