void SortedStack :: sort()
{
    if(s.size()==0){
        return;
    }
    int x = s.top();
    s.pop();
    sort();
    stack<int>st;
    while(!s.empty() && s.top()>x){
        // x to be pushed below
        st.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!st.empty()){
        // x to be pushed below
        s.push(st.top());
        st.pop();
    }
   
}
