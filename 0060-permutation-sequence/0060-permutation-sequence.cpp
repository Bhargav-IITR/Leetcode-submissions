class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector <int> t;
        for(int i = 1; i < n ; i++){
            fact = fact*i;
            t.push_back(i);
        }
        t.push_back(n);
        k = k-1;
        string ans = "";
        while(t.size()){
            ans = ans + to_string(t[k/fact]);
            t.erase(t.begin() + (k/fact));
            k = k%fact;
            if(t.size())fact = fact/t.size();
        }
        return ans;
    }
};