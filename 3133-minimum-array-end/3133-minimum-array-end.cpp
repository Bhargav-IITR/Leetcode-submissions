#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        ll ans = (ll)x;
        ll t = n-1;
        int i = 0;
        while(t){
            if(((ll)x&((ll)1<<i)) == 0){
                if(t&1){ 
                    ans |= ((ll)1<<i);
                }
                t >>= 1;
            }
            i++;
        }
        return ans;
    }
};