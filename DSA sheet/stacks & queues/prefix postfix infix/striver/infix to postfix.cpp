// gfg q

class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        int i=0, n = s.length(); stack<char>st;
        unordered_map<char, int>mpp;
        mpp['+'] = mpp['-'] = 1;
        mpp['*'] = mpp['/'] = 2;
        mpp['^'] = 3;
        string ans = "";
        for(int j=0; j<n; j++){
            if((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')){
                ans += s[j];
            }
            else if(s[j]=='(') st.push(s[j]);
            else if(s[j]==')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(!st.empty() && mpp[st.top()]<mpp[s[j]]) st.push(s[j]);
                else{
                    while(!st.empty() && mpp[st.top()]>=mpp[s[j]]){
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[j]);
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
