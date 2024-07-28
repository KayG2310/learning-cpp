vector<int> Solution::prevSmaller(vector<int> &a) {
    vector<int>ans(a.size());
    //int n = a.size();
    stack<int>st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() && st.top()>=a[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(a[i]);
    }
    return ans;
}
// question link - https://www.interviewbit.com/problems/nearest-smaller-element/
