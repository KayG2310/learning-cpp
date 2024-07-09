class Solution {
public:
    int romanToInt(string s) {
        int final=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='M'){
                final+=1000;
                i+=1;
            } 
            // M done
            else if(s[i]=='D'){
                final+=500;
                i+=1;
            } 
            // D Done
            else if(s[i]=='C'){
                if(s[i+1]=='D'&& i+1<s.length()){
                    final+=400;
                    i+=2;
                }
                else if(s[i+1]=='M'&& i+1<s.length()){
                    final+=900;
                    i+=2;
                } 
                else{
                    final+=100;
                    i+=1;
                }
            } 

            else if(s[i]=='L'){
                final+=50;
                i+=1;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'&& i+1<s.length()){
                    final+=40;
                    i+=2;
                }
                else if(s[i+1]=='C'&& i+1<s.length()){
                    final+=90;
                    i+=2;
                } 
                else{
                    final+=10;
                    i+=1;
                }
            }
            else if(s[i]=='V'){
                final+=5;
                i+=1;
            }
            else{
                if(s[i+1]=='V'&& i+1<s.length()){
                    final+=4;
                    i+=2;
                }
                else if(s[i+1]=='X'&& i+1<s.length()){
                    final+=9;
                    i+=2;
                } 
                else{
                    final+=1;
                    i+=1;
                }
            }

        }
        return final;
    }
};
