class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
       while(st.empty() == false) st.pop();
       mini = INT_MAX; 
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else{
            if(value<mini){
                st.push(2*value - mini);
                mini = value;
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el<mini){
            // meaning it was modified
            mini = 2*mini - el;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        if(el<mini) return mini;
        return (int)el;
    }
    
    int getMin() {
        return (int)mini;
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
