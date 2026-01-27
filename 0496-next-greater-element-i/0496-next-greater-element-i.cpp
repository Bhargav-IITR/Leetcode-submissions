class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st; // monotonic stack
        int n = nums2.size();
        map<int,int> mp;
        for(int i = n-1 ; i>=0 ;i--){
            while(!(st.empty()) && nums2[st.top()] <= nums2[i]){
                st.pop();
            }
            if(!st.empty()) mp[nums2[i]] = st.top();
            st.push(i);
        }
        vector<int> ans;
        for(auto it : nums1){
            if(mp.find(it) != mp.end()) ans.push_back(nums2[mp[it]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};