class Solution {
public:
    bool canDo(vector <int> &w, int days, int cap){
        int temp = 0;
        int n = w.size();
        int day = 1;
        for(int i = 0; i< n; i++){
            temp += w[i];
            if(temp > cap){
                temp = w[i];
                day++;
                if(day > days) return false;
            }
        }
        if(day > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = INT_MIN, hi = 0;
        for(auto it : weights) {
            lo = max(lo, it);
            hi += it;
        }
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(canDo(weights, days, mid)){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        return ans;
    }
};

