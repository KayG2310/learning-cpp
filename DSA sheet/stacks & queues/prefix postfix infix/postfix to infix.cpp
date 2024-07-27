class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        string infix = "";
        for(int i=0; i<exp.length(); i++){
            if((exp[i]-'a'>=0 && exp[i]-'a'<=25) || (exp[i]-'0'>=0 && exp[i]-'0'<=9) || (exp[i]-'A'>=0 && exp[i]-'A'<=25)){
                string temp = "";
                temp = temp+exp[i];
                st.push(temp);
            }
            else{
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                st.push("("+B+exp[i]+A+")");
            }
        }
        infix = st.top();
        st.pop();
        return infix;
    }
};
