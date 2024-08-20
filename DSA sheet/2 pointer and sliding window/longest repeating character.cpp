// brute force n2, o(256)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        for(int i=0; i<s.length(); i++){
            int arr[256] = {0};
            int maxfreq = 0;
            for(int j=i; j<s.length();j++){
                arr[s[j]]++;
                maxfreq = max(maxfreq, arr[s[i]]);
                int changes = j-i+1- maxfreq;
                if(changes<=k){
                    maxlen = max(maxlen,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0, l=0,r=0,maxf=0;
        int hash[26] = {0};
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            if(r-l+1-maxf>k){
                hash[s[l]-'A']--;
                maxf = 0;
                l++;
            }
            if(r-l+1-maxf<=k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
