class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> pf(n+1,0);   
        pf[0] = 0;
        int ans =INT_MAX;
        for(int i = 1 ; i <=n ; i++) pf[i] = pf[i-1] + nums[i-1];
        deque <int> dq; // stores index
        dq.push_front(0);
        for(int i = 1 ; i <= n; i++){
            while(!dq.empty() && (pf[dq.back()] >= pf[i])){
                dq.pop_back();
            }
            dq.push_back(i);
            while(pf[i] - pf[dq.front()] >= k) {
                ans = min(ans, i-dq.front());
                dq.pop_front();
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};