class MyStack {
    private:
        queue<int>q1;
        queue<int>q2;
    public:
        void push(int x) {
            q2.push(x);
            while(! q1.empty()){
                int y = q1.front();
                q1.pop();
                q2.push(y);
            }
            while(! q2.empty()){
                int y = q2.front();
                q1.push(y);
                q2.pop();
            }
        }
        
        int pop() {
            int y = q1.front();
            q1.pop();
            return y;
        }
        
        int top() {
            return q1.front();
        }
        
        bool empty() {
            if(q1.size() == 0) return true;
            return false;
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

