class Solution {
  public:
    string preToPost(string exp) {
        // prefix to postfix
        // Write your code here
        stack<string>st;
        for(int i=exp.length()-1; i>=0; i--){
            if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='0' && exp[i]<='9')
            || (exp[i]>='A' && exp[i]<='Z')){
                string temp = "";
                temp +=exp[i];
                st.push(temp);
            }
            else{
                string temp = "";
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                temp = t1+t2+exp[i];
                st.push(temp);
            }
        }
        return st.top();
    }
};
