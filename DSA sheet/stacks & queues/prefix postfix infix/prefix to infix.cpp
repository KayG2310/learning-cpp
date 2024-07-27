class Solution {
  public:
    string preToInfix(string exp) {
        stack<string> st;
        string infix = "";
        for(int i=exp.length()-1; i>=0; i--){
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
        for(int i=st.top().length()-1; i>=0; i--){
            if(st.top()[i] == '('){
                infix+=')';
            }
            else if(st.top()[i] == ')'){
                infix+='(';
            }
            else infix+=st.top()[i];
        }
        st.pop();
        return infix;
    }
};
