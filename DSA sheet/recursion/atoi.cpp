// iterative 
class Solution {
public:
    int myAtoi(string s) {
        long long ans =0;
        bool negative = false;
        int read=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]-'0'<0 || s[i]-'0'>9) {
                if(s[i]=='-'){
                    if(read>0 || s[i+1]-'0'<0 || s[i+1]-'0'>9) break;
                    negative = true;
                    continue;
                }
                else if(s[i]==' ' && read>0) break;
                else if(s[i]==' ') continue;
                else if(s[i]=='+' && read>0) break;
                else if(s[i]=='+') {read++; continue;}
                else break;
            }
            // break the loop if you encounter something like thid
            else{
                // we have a number
                read++;
                if(ans*10+(s[i]-'0')<INT_MIN || ans*10+(s[i]-'0')>INT_MAX){
                    if(negative==true) return INT_MIN;
                    return INT_MAX;
                }
                ans = ans*10 + (s[i]-'0');
            }
        }
        if(negative==true) return (int)(-1*ans);
        return (int)ans; 
    }
};
