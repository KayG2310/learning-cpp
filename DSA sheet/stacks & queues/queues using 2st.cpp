class MyQueue {
private:
    stack<int>input;
    stack<int>output;
public:
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(! output.empty()){
            int y = output.top();
            output.pop();
            return y;
        }
        else {
            while(! input.empty()){
                int y = input.top();
                input.pop();
                output.push(y);
            }
            int z = output.top();
            output.pop();
            return z;
        }
        return -1;
    }
    
    int peek() {
        if(! output.empty()){
            return output.top();
        }
        else{
            while(! input.empty()){
                int y = input.top();
                input.pop();
                output.push(y);
            }
            return output.top();
        }
        return -1;
    }
    
    bool empty() {
        if(input.empty() == true && output.empty() == true){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
