class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char ctop = st.top();
                    if((s[i] == ')' && ctop == '(') || (s[i] == '}' && ctop == '{') || (s[i] == ']' && ctop == '[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};