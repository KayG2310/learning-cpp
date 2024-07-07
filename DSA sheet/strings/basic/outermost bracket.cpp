class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int checker = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                // opening braces need to be included
                // if balance is - 0 it is outermost else not
                if(checker>0) result+=s[i];
            checker++;
            }
            else{
                checker--;
                if(checker>0) result+=s[i];
            }
        }
        return result;
    }
};

// dry run -->
/*
(()()
)
(()) length = 10
result = "" checker = 1
result = ( checker = 2
checker = 1, 1 is balanced and it needs to be closed result = ()
()( checker = 2
checker = 1 ()()
checker = 0, it is outermost, hence not added
ooh

*/
