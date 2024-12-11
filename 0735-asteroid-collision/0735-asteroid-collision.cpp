class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector <int> ans;
        stack <int> st; // will contain the index
        int n = a.size();
        for(int i = 0 ; i < n ;i++){
            if(a[i] > 0) st.push(i);
            else{
                bool exist = true;
                while(!st.empty() && a[st.top()] >= 0 && a[st.top()] <= abs(a[i])){
                    int t = a[st.top()];
                    st.pop();
                    if(t == abs(a[i])){
                        exist = false;
                        break;
                    }
                }
                if(!st.empty() && a[st.top()] > 0) exist = false;
                if(exist) st.push(i);
            }
        }
        while(!st.empty()){
            ans.push_back(a[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};