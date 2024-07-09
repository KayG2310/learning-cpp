class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open=0,cnt=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                //meaning a brace is open
                open++;
            }
            else if(s[i]==')'){
                // one brace is getting closed
                ans = max(ans,open);
                open--;
            }
        }
        return ans;
    }
};
