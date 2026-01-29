class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        stack <int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()] <= height[i]){
                int base = height[st.top()];
                st.pop();
                int left = (!st.empty())?height[st.top()]:-1;
                int right = height[i];
                int width = i-1-((st.empty())?-1:st.top());
                if(left != -1) ans += (min(left,right)-base)*width;
            }
            st.push(i);
        }
        return ans;
    }
};