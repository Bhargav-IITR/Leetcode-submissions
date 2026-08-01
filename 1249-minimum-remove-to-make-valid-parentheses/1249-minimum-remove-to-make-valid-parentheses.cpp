class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack <int> st;
        int n = s.length();
        vector <int> a(n, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') {
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty()){
                    int id = st.top();
                    a[id] = 1;
                    a[i] = 1;
                    st.pop();
                }
            }
            else a[i] = 1;
        }
        for(int i = 0 ;i <n ;i++) if(a[i] == 1) ans += s[i];
        return ans;
    }
};