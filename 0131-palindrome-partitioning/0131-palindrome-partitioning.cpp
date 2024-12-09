class Solution {
public:
    vector <vector <string>> ans;
    vector <vector<bool>> pal(string &s){
        int n = s.length();
        vector<vector<bool>> p(n, vector<bool>(n,false));
        for(int len = 1 ; len <= n ; len++){
            for(int i = 0 ; i < n ; i++){
                int j = i + len-1;
                if(len == 1) p[i][i] = true;
                else if(j < n){
                    if(len == 2) p[i][j] = (s[i] == s[j]);
                    else if(s[i] == s[j] && p[i+1][j-1]) p[i][j] = true;
                }
            }
        }
        return p;
    }

    void func(int i, string &s,vector <string> &temp,  vector<vector<bool>> &ispal){
        if(i == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int j = i ; j < s.length() ; j++){
            if(ispal[i][j]){
                temp.push_back(s.substr(i,j-i+1));
                func(j+1, s, temp, ispal);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector <vector<bool>> ispal = pal(s);
        vector <string> temp;
        func(0,s,temp,ispal);
        return ans;
    }
};