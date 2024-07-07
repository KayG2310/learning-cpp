class Solution {
private:
    string palindrome(string k){
        string result="";
        for(int i=k.size()-1; i>=0; i--){
            result+=k[i];
        }
        return result;
    }
public:
    string reverseWords(string s) {
        string finals="", inner="";
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' '){
                // means it is a valid char 
                if(inner=="") continue;
                finals= finals+palindrome(inner)+' ';
                inner = "";
            }
            else{
                inner+=s[i];
            }
        }
        finals+=palindrome(inner);
        int cnt=0;
        for(int i=finals.size()-1; i>=0; i--){
            if(finals[i]==' ') cnt++;
            else break;
        }
        finals = finals.substr(0,finals.size()-cnt);
        return finals;
    }
};
// dry run 
/*
s= the sky is blue
inner = eulb 
finals = blue_
inner = ""
si finals blue_is_
inner = sky
finals = blue_is_sky_
inner = eth

*/
