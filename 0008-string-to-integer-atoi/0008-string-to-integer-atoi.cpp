class Solution {
public:
#define ll long long
    int myAtoi(string s){
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+') i++;
        
        ll ans = 0;
        while(!(i == n || s[i] < '0' || s[i] > '9' )){
            if(neg) ans = ans*10 - (s[i]-'0');
            else ans = ans*10 + (s[i]-'0');
            if(ans > INT_MAX) return INT_MAX;
            if(ans < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)ans;
    }
};