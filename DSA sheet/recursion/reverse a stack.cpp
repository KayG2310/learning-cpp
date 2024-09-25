class Solution{
private:
    void pushbottom(stack<int>&st, int x){
        if(st.size()==0){
            st.push(x);
            return;
        }
        int y = st.top();
        st.pop();
        pushbottom(st,x);
        st.push(y);
    }
public:
    void Reverse(stack<int> &st){
        // ulti base condition
        if(st.size()>0){
            int x = st.top();
            st.pop();
            Reverse(st);
            pushbottom(st,x);
        }
        return;
        
    }
};
