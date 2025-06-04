class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq; // stores the indices in a decreasing manner of their value from left to right
        // the left of dq for any valid window will give the maximum of that window
        vector <int> ans;
        for(int i = 0 ; i < nums.size(); i++){
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front(); //ensuring k size window
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        } 
        return ans;
    }
};