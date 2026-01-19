class Solution {
public:
#define ll long long
const int M = 1e9+7;
    int binExpIterative(ll a, ll b){
        int ans = 1;
        while(b){
            if(b&1){
                ans = ((ll)ans*a)%M;
            }
            a = (a*a)%M;
            b >>= 1;
        }
        return ans;
    }
    int binMultiplyIterative(int a, int b){
        int ans = 0;
        while(b){
            if(b&1){
                ans = (ans + a)%M;
            }
            a = (a+a)%M;
            b >>=1 ;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        int a = binExpIterative((ll)5, (n+1)/2);
        int b = binExpIterative((ll)4, n/2);
        int ans = binMultiplyIterative(a, b);
        return ans;
    }
};