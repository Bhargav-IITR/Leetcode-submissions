class Solution {
public:
    void writeTochars(int cnt, char c, vector <char>&chars, int &res){
        if(cnt == 1) chars[res++] = c;
        else{
            chars[res++] = c;
            string s = to_string(cnt);
            int i = 0;
            while(i<s.length()){
                chars[res++] = s[i];
                i++;
            }
        } 
    }
    int compress(vector<char>& chars) {
        int i = 0;
        int res = 0;
        int n = chars.size();
        while(i < n){
            int cnt = 0;
            char c = chars[i];
            while(i < n && chars[i] == c) cnt++, i++;
            writeTochars(cnt, c, chars, res);
        }
        return res;
    }
};