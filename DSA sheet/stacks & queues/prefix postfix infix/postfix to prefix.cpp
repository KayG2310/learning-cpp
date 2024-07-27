class Solution {
  public:
    string postToPre(string exp) {
        // Write your code here
        stack<string>st;
        for(int i=0; i<exp.length(); i++){
            if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='0' && exp[i]<='9')
            || (exp[i]>='A' && exp[i]<='Z')){
                string temp = "";
                temp +=exp[i];
                st.push(temp);
            }
            else{
                string temp = "";
                string t2 = st.top();
                st.pop();
                string t1 = st.top();
                st.pop();
                temp = exp[i]+t1+t2;
                st.push(temp);
            }
        }
        return st.top();
    }
};
