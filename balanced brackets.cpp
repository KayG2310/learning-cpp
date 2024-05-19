#include<bits/stdc++.h>
using namespace std;
string isBalanced(string s) {
    stack<char>st;
    if(s.length()%2!=0){
            return "NO";
        }
    for(int i=0; i< s.length(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
        st.push(s[i]);
        
        } 
        
        
        else {
            
            if(s[i]==')' && !st.empty()){
                if(st.top()=='('){
                    st.pop();
                } else {
                    return "NO";
                }
            }
            
            else if(s[i]=='}' && !st.empty()){
                if(st.top()=='{'){
                    st.pop();
                } else {
                    return "NO";
                }
            }
            
            else if(s[i]==']' && !st.empty()) {
                if(st.top()=='['){
                    st.pop();
                 }
                 else {
                    return "NO";
                }
                }
                
            else{
                return "NO";
                }
                
            }
        }
    
    if(!st.empty()){
       return "NO"; 
    } else {
       return "YES";
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s2;
        cin>>s2;
        cout<< isBalanced(s2)<<endl;
    }
}
