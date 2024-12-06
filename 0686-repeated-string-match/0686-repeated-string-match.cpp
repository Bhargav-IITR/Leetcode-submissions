class Solution {
public:
    #define ll long long
    int M = 1e9+7;
    bool rabinKarp(string &s, string &t){
        
        int n = s.length(), m = t.length();
        //calculate hash of pattern t and first window of s:
        
        ll seq = 0, pat = 0;
        ll  h = 1;
        for(int i = 0 ; i < m-1 ; i++) h = (h*26)%M;
        for(int i = 0 ;i < m ; i++){
            seq = (seq*26 + s[i]-'a'+1)%M;
            pat = (pat*26 + t[i]-'a'+1)%M;
        }
        if(seq == pat){
            if(s.substr(0,m) == t) return true;
        }
        for(int i = m ; i < n ; i++){
            seq = ((seq - (s[i - m]-'a'+1) * h) * 26 + (s[i] - 'a') + 1) % M;
            if(seq < 0) seq += M;
            if(seq == pat){
                if(s.substr(i-m+1,m) == t) return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        int n = a.length(), m = b.length();
        if(m == 0) return 0; 
        int times = (m/n);
        if(m%n != 0) times++;
        string c = "";
        for(int i = 1 ; i <= times; i++) c += a;
        if(c == b) return times;
        if(rabinKarp(c,b)) return times;
        c = c+a;
        if(rabinKarp(c,b)) return times+1;
        return -1;
    }
};