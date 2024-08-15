class Solution {
public:
    char andHelp(string &s){
        bool ans = true;
        for(char c:s) if(c == 'f') ans = false;
        return (ans)?'t':'f';
    }
    char orHelp(string &s){
        bool ans = false;
        for(char c : s) if(c == 't') ans = true;
        return (ans)?'t':'f';
    }
    char notHelp(string &s){
        if(s[0] == 't') return 'f';
        return 't';
    }

    char val(char op, string &s){
        if(op == '&') return andHelp(s);
        else if(op == '|') return orHelp(s);
        else return notHelp(s);
    }

    bool parseBoolExpr(string s) {
        stack <char> st;
        for(int i = 0  ; i < s.length() ; i++){
            if(s[i] == ')'){
                string tmp = "";
                while(!st.empty() && st.top() != '('){
                    tmp += st.top();
                    st.pop();
                }
                st.pop(); // removes (
                char c = val(st.top(), tmp);
                st.pop();
                st.push(c);
            }else{
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};