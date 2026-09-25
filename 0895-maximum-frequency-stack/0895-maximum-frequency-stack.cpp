class FreqStack {
public:
    map <int, int> freq;
    map <int, stack <int>> m;
    int maxf = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxf = max(maxf, freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int x =m[maxf].top();
        m[maxf].pop();
        freq[x]--;
        if(m[maxf].size() == 0) maxf--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */