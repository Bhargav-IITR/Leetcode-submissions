class Solution {
public:
    bool possible(int k, vector <int> &p, int h){
        int hrs = 0;
        for(auto it : p){
            hrs += (it/k);
            if(it%k) hrs++;
            if(hrs > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = INT_MIN;
        for(auto it : piles) hi = max(hi, it);
        int ans;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(possible(mid, piles, h)){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        return ans;
    }
};