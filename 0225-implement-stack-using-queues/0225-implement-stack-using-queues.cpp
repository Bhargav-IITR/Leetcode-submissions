class MyStack {
public:
    queue <int> q1;
    //queue <int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        ///q2 = q1;
        queue <int> q2;
        int last;
        int n = q1.size();
        if(n != 1){
            while(q1.size() != 1){
                int ele = q1.front();
                q1.pop();
                q2.push(ele);
            }
            int topele = q1.front();
            q1 = q2;
            return topele;
        }
        else{
            int topele = q1.front();
            q1.pop();
            return topele;
        }
    }
    
    int top() {
        queue <int> q3 = q1;
        int last;
        while(!(q3.empty())){
            last = q3.front();
            q3.pop();
        }        
        return last;
    }
    
    bool empty() {
        if(q1.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */