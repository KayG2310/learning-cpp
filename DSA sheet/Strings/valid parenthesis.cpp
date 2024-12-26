class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }
}; 

// tc = n, sc = n

class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char>st;
        int open = 0;
        int other = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='(') open++;
            else{
                if(open>0) open--;
                else other++;
            }
        }
        return open+other;
    }
};
// tc = n, sc = 1
