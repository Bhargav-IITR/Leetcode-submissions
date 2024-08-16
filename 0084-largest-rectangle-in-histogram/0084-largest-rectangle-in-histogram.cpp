class Solution {
public:
    vector <int> pse(vector <int> &heights){
        vector <int> ans(heights.size(), -1);
        stack<int>st;
        for(int i = 0 ; i < heights.size() ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> nse(vector <int> &heights){
        vector <int> ans(heights.size(), heights.size());
        stack<int>st;
        for(int i = heights.size()-1 ; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        // vector <int> p = pse(heights);
        // vector <int> n = nse(heights);
        // int ans = 0;
        // for(int i = 0 ; i < heights.size() ; i++){
        //     int left = p[i], right = n[i];
        //     ans = max(ans, (right-left-1)*heights[i]);
        // }
        // return ans;

        stack <int> st;
        int ans = 0;
        for(int i = 0 ; i <= heights.size() ; i++){
            while(!st.empty() && (i == heights.size() || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int left = (st.empty())?-1:st.top();
                int right = i;
                ans = max(ans, height*(right-left-1));
            }
            st.push(i);
        }
        return ans;
    }
};