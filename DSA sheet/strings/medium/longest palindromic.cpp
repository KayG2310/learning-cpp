// brute force, did not get submitted 
/*

class Solution {
private:
    bool checkpalin(string s){
        
        string x="";
        for(int i=s.length()-1; i>=0; i--){
            x+=s[i];
        }
        if(x==s) return true;
        return false;
        
        int low=0, high = s.length()-1;
        while(low<=high){
            if(s[low]==s[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int low=0, high = s.length()-1;
        while(high>=low){
            string x = s.substr(low, high-low+1);
            if(checkpalin(x)==true) {ans=x; break;}
            else{
                if(s[low+1]==s[high]){
                    low++;
                }
                else if(s[low]==s[high-1]){
                    high--;
                }
                else{
                    low++;
                    high--;
                }
            }
        }
        string ans1 = "", ans2="";
        low=0, high = s.length()-1;
        while(high>=low){
            string x = s.substr(low, high-low+1);
            if(checkpalin(x)==true) {ans1= x; break;}
            else{
                low++;
            }
        }
        low=0, high = s.length()-1;
        while(high>=low){
            string x = s.substr(low, high-low+1);
            if(checkpalin(x)==true) {ans2= x; break;}
            else{
                high--;
            }
        }
        
        if(ans.length()>=ans1.length() && ans.length()>=ans2.length()){
            return ans;
        }
        else if(ans1.length()>=ans.length() && ans1.length()>=ans2.length()){
            return ans1;
        }
        else{
            return ans2;
        }
        return "";
    }
};
*/

// youtube solution
class Solution {
public:
    string longestPalindrome(string str) {
        if (str.length() <= 1) return str;

        string LPS = "";

        for (int i = 0; i < str.length(); i++) {
            // Consider odd length palindromes
            int low = i;
            int high = i;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                low--;
                high++;
            }

            string palindrome = str.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }

            // Consider even length palindromes
            low = i - 1;
            high = i;
            while (low >= 0 && high < str.length() && str[low] == str[high]) {
                low--;
                high++;
            }

            palindrome = str.substr(low + 1, high - low - 1);
            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }
        }

        return LPS;
    }
};
// check for odd and even palindromes
