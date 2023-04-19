class MinStack {
public:
    stack<long> st;
    long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(long val) {
        if(st.empty()){
            st.push(val);
            mini = val;
            return;
        }
        if(val < mini){
            long data = 2*val-mini;
            st.push(data);
            mini = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long curr = st.top();
        st.pop();
        if(curr > mini){
            return;
        }
        else{
            long prevmini = mini;
            long val = 2*mini-curr;
            mini = val;
            return;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(mini<st.top())
            return st.top();
        else
            return mini;
        
    }
    
    int getMin() {
        if(!st.empty())
            return mini;
        return -1;
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