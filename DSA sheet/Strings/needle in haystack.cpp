class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int k = needle.length();
        for(int i=0; i<n; i++){
            if(haystack[i]!=needle[0]) continue;
            bool flag = true;
            for(int j=1; j<k; j++){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};
