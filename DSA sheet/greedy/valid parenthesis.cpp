// n, sc = 1
class Solution {
public:
    bool checkValidString(string s) {
        int max = 0, min = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                if(min>0){
                    min--;
                    max--;
                }
                else if(max>0){
                    max--;
                }
                else{
                    return false;
                }
            }
            else{
                if(min>=1){
                    min--;
                }
                max++;
            }
        }
        if(0>=min && 0<=max){
            return true;
        }
        return false;
    }
};

/*
))*))())()(**(((())(()(*()((((())))*())(())*(*(()(*)))()*())**((()(()))())(*(*))*))())
min = 4, max = 4
min = 1, max = 1
min = 0, max = 0

min = 5, max = 5
min = 4, max = 6
min = 3, max = 5
min = 1, max = 3
min = 0, max = 4
min = 0, max = 5
*/
