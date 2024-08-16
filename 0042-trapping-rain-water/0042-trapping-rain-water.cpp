class Solution {
public:
    int trap(vector<int>& height) {
        // tc- o(n) , sc - o(n)
        // stack <int> st;
        // int n = height.size();
        // int ans = 0;
        // for(int i = 0 ; i < n ; i++){
        //     while(!st.empty() && height[st.top()] <= height[i]){
        //         int currHeight = height[st.top()];
        //         st.pop();
        //         if(st.empty()) break;
        //         int leftHeight = height[st.top()];
        //         int rightHeight = height[i];
        //         int width = i-st.top()-1;
        //         ans += (min(leftHeight,rightHeight)-currHeight)*width;
        //     }
        //     st.push(i);
        // }
        // return ans;

        // tc - o(n) , sc - o(1):
        int n = height.size();
        int l = 0, r = n-1, lmax = 0, rmax = 0, total = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    total += (lmax-height[l]);
                }
                else lmax = height[l];
                l++;
            }else{
                if(rmax > height[r]){
                    total += (rmax-height[r]);
                }
                else rmax = height[r];

                r--;
            }
        }
        return total;
    }
};