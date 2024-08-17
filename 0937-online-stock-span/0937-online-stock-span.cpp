class StockSpanner {
public:
    // stack <int> st;
    // map <int,int> mp;
    // StockSpanner() {
    // }
    
    // int next(int price) {
    //     int ans = 1;
    //     while(!st.empty() && st.top() <= price){
    //         int t = st.top();
    //         st.pop();
    //         ans += mp[t];
    //     }
    //     st.push(price);
    //     return mp[price] = ans;
    // }

    stack <pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        while(!st.empty() && st.top().first <= price){
            auto t = st.top();
            st.pop();
            ans += t.second;
        }
        st.push({price, ans});
        return ans;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */