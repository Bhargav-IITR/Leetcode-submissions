class Solution {
public:
    bool possible(int m, int k, int mn, vector <int> &day){
        int numBouq = 0;
        int cnt = 0;
        for(int i = 0 ; i < day.size() ; i++){
            if(day[i] <= mn){
                cnt++;
                if(cnt == k) numBouq++ , cnt = 0;
                if(numBouq == m) return true;
            }else{
                cnt = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = INT_MAX, hi = INT_MIN;
        for(auto it : bloomDay){
            lo = min(lo, it);
            hi = max(hi, it);
        }

        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(possible(m, k, mid, bloomDay)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};