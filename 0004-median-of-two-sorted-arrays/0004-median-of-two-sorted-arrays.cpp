class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(m < n) return findMedianSortedArrays(b,a);
        int lo = 0, hi = n;
        while(lo <= hi){
            int cut1 = (lo+hi)/2;
            int cut2 = (m+n+1)/2 - cut1;
            int l1 = (cut1 == 0)? INT_MIN: a[cut1-1];
            int r1 = (cut1 == n)? INT_MAX:a[cut1];
            int l2 = (cut2 == 0)? INT_MIN: b[cut2-1];
            int r2 = (cut2 == m)? INT_MAX: b[cut2];
            if(l1 <= r2 && l2 <= r1){
                if((m+n)&1){
                    return max(l1,l2);
                }
                else{
                    double ans = (max(l1,l2)+min(r1,r2))/2.0;
                    return ans;
                }
            }
            else if(l1 > r2){
                hi = cut1-1;
            } 
            else if(l2 > r1) lo = cut1+1;
        }
        return -1;
    }
};