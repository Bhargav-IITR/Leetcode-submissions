class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0;
        map <int, int> st;
        int ans = 0;
        int n = fruits.size();
        while(r < n){
            if(st.find(fruits[r]) == st.end()){
                if(st.size() == 2){
                    while(l < r && st.size() == 2){
                        st[fruits[l]]--;
                        if(st[fruits[l]] == 0) st.erase(fruits[l]);
                        l++;
                    }
                }
            }
            st[fruits[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};