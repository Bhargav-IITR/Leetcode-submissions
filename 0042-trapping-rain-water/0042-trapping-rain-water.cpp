class Solution {
public:
    // vector <int> prevLarge(vector <int> &a){
    //     vector <int> ans;
    //     ans.push_back(0);
    //     int ma = a[0];
    //     for(int i = 1 ; i < a.size() ; i++){
    //         if(a[i] <= ma){
    //             ans.push_back(ma);
    //         }
    //         else{
    //             ma = a[i];
    //             ans.push_back(0);
    //         }
    //     }
    //     return ans;
    // }
    // vector <int> nextLarge(vector <int> &a){
    //     vector <int> ans;
    //     ans.push_back(0);
    //     int ma = a[a.size()-1];
    //     for(int i = a.size()-2 ; i >= 0 ; i--){
    //         if(a[i] <= ma){
    //             ans.push_back(ma);
    //         }
    //         else{
    //             ma = a[i];
    //             ans.push_back(0);
    //         }
    //     }
    //     reverse(ans.begin() , ans.end());
    //     return ans;
    // }
    // int trap(vector<int>& height) {
    //     vector <int> pre = prevLarge(height);
    //     vector <int> next = nextLarge(height);
    //     int ans = 0;
    //     for(int i = 0 ; i < height.size() ; i++){
    //         ans += max(min(pre[i], next[i]) - height[i] , 0);
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height) {
        stack <int> st;
        int ans = 0;
        for(int i = 0 ; i < height.size() ; i++){
            while(!st.empty() && height[st.top()] <= height[i]){
                int x = st.top();
                st.pop();
                if(!st.empty()) ans += max((min(height[i], height[st.top()]) - height[x])*(i - st.top() - 1) , 0);
            }
            st.push(i);
        }
        return ans;
    }
};