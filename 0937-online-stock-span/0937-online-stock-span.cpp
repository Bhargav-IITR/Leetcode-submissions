class StockSpanner {
public:
    stack <pair<int,int>> st;
    int ind = 0;
    StockSpanner() {
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push(make_pair(price, ind));
        ind++;
        return ans;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */