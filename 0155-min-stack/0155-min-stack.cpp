class MinStack {
public:
    vector< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
};

// class MinStack {
// public:
//     stack<int> st;
//     int mini;
//     MinStack() {
//         mini = INT_MAX;
//     }
    
//     void push(long long val) {
//         if(st.empty()){
//             st.push((int)val);
//             mini = val;
//             return;
//         }
//         if(val < mini){
//             long long data = 2*val-mini;
//             st.push((int)data);
//             mini = val;
//         }
//         else{
//             st.push((int)val);
//         }
//     }
    
//     void pop() {
//         if(st.empty()){
//             return;
//         }
//         long long curr = st.top();
//         st.pop();
//         if(curr > mini){
//             return;
//         }
//         else{
//             long long prevmini = mini;
//             long long val = 2*mini-curr;
//             mini = val;
//             return;
//         }
//     }
    
//     int top() {
//         if(st.empty())
//             return -1;
//         if(mini<st.top())
//             return st.top();
//         else
//             return mini;
        
//     }
    
//     int getMin() {
//         if(!st.empty())
//             return mini;
//         return -1;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */