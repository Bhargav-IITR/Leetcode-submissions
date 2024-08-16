class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        for(int i = 0 ; i < num.length() ; i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.length() > 0 && ans[ans.length()-1] == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans.length() == 0) ans = "0";
        return ans;
    }
};