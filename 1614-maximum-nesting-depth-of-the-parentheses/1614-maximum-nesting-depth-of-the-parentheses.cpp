class Solution {
public:
    int maxDepth(string s) {
        int b = 0;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                b++;
                ans = max(ans, b);
            }else if(s[i] == ')'){
                b--;
            }
        }
        return ans;
    }
};