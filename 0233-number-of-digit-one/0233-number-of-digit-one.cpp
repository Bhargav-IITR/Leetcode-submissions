#define ll long long
class Solution {
public:
    int countDigitOne(int n) {
        ll ans = 0;
        ll factor = 1;
        ll lo = 0;
        while(n){
            ll curr = n%10;
            ll hi = n/10;
            if(curr == 0){
                ans += (hi*factor);
            }else if(curr == 1){
                ans += (hi*factor + lo + 1);
            }else{
                ans += ((hi+1)*factor);
            }
            lo += curr*factor;
            factor *= 10;
            n = hi;
        }
        return (int)ans;
    }
};