// using stacks
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.size() == 0) return false;
                // means it is a closing bracket and needs to be compared  with the top
                if(s[i] == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }
                else if(s[i] == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
                else if(s[i] == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }
                else{
                    return false;
                }
            }
        }
        if(st.size() != 0) return false;
        return true;
    }
};
