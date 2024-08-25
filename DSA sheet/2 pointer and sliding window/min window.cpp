// brute force n^2, sc = 256
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        //s=a, t=b
        int minlen = 1e9, startIndex = -1;
        for(int i=0; i<s.length(); i++){
            int hash[256] = {0};
            int cnt = 0;
            for(int j=0; j<t.length(); j++){
                hash[t[j]]++;
            }
            // hashmap 0 1 0 0 0 0 0 0
            for(int j=i; j<s.length(); j++){   //j=0
                if(hash[s[j]]>0) cnt++;
                hash[s[j]]--; // hashmap -1 1 0 0 0 0 0 0
                if(cnt==t.length()){
                    if(j-i+1<minlen){
                        minlen = j-i+1;
                        startIndex = i;

                        break;
                    }
                }
            }
            //cout<< s.substr(startIndex,minlen)<<endl;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minlen);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";
        //s=a, t=b
        int minlen = 1e9, startIndex = -1, l=0, r=0, cnt=0;
        unordered_map<char, int>f;
        for(int i=0; i<t.length(); i++){
            f[t[i]]++;
        }
        while(r<s.length()){
            if(f[s[r]]>0) cnt++;
            f[s[r]]--;
            while(cnt==t.length()){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    startIndex = l;
                }
                f[s[l]]++;
                if(f[s[l]]>0) {cnt--;}
                l++;
            }
            r++;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minlen);
    }
};
