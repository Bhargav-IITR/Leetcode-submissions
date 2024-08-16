class MinStack {
public:
    stack <pair<int,int>> st; // stack of pair of top element and min till now element
    MinStack() {
    }
    
    void push(int val) {
        int minTillNow = (!st.empty())?min(st.top().second, val):val;
        st.push({val, minTillNow});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */