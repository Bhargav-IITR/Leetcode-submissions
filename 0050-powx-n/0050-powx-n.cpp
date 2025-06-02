class Solution {
public:
    double func(double x, long long int n){
        if(n == 0) return 1;
        if(x == 0) return 0;
        if(n > 0){
            double res = myPow(x, n/2);
            if(n&1) return x*res*res;
            return res*res;
        }else{
            n = abs(n);
            double res = myPow(x, n/2);
            if(n&1) return 1.0/(x*res*res);
            return 1.0/(res*res);
        }
    }
    double myPow(double x, int n) {
        return func(x, (long long int)n);
    }
};