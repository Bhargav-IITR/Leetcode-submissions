class Solution {
public:
    string removeOuterParentheses(string s) {
      int b = 0;
      string ans = "";
      for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            if(b > 0) ans += s[i];
            b++;
        }else{
            b--;
            if(b > 0) ans += s[i];
        }
      }  
      return ans;
    }
};