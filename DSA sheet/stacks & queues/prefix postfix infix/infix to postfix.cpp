#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string s) {
    stack<char> st;
    string postfix = "";
    for(int i=0; i<s.length(); i++){
        if((s[i]-'a'>=0 && s[i]-'a'<=25) || (s[i]-'A'>=0 && s[i]-'A'<=25) || (s[i]-'0'>=0 && s[i] - '0'<=9)){
            // meaning it is an alphabet
            postfix +=s[i];
        }
        else if(st.empty()== true){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top() != '('){
                char x = st.top();
                postfix += x;
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else if(!st.empty() && st.top() == '('){
            st.push(s[i]);
        }
        else if(s[i]=='^'){
            if(!st.empty() && st.top() == '^'){
                postfix += '^';
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '/' || s[i] == '*'){
            // they can be lower to exponential only
            while(!st.empty() && st.top() == '^'){
                postfix+='^';
                st.pop();
            }
            while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                // same precedence but goes from left to right
                postfix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='+' || s[i] == '-'){
            // pop the higher precedence operators first
            while(!st.empty() && (st.top() != '+' && st.top() != '-' && st.top() != '(')){
                postfix += st.top();
                st.pop();
            }
            
            while(!st.empty() && (st.top() == '+' || st.top() == '-')){
                postfix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    cout<<infixToPostfix("h^m^q^(7-4)");
}
