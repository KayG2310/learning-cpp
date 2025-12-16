// brute force technique ---> O(n2) sc = O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        
        for(int i=0; i<s.length(); i++){
            int hash[256] = {0};
            for(int j=i; j<s.length(); j++){
                if(hash[s[j]]==1) {
                    break;
                }
                maxlen = max(maxlen, j-i+1);
                hash[s[j]] = 1;

            }    
        }
        return maxlen;
    }
};
/*
dry run : abcabcbb
i = 0
j = 0 hash[a] // automatically accesses the ascii value 
*/

// optimal approach is using two pointers
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        for(int i=0; i<256; i++) hash[i] = -1;
        int maxlen = 0;
        int l=0, r=0;
        while(r<s.length()){
            if(hash[s[r]] != -1 && hash[s[r]]>=l){
                l = hash[s[r]] + 1;
            }
            maxlen = max(maxlen, r-l+1);
            hash[s[r]] = r;
            r++;

        }
        return maxlen;
    }
};
/*
dry run : tmmzuxt
l = 0, r = 0
t not in map, map = (t, 0) maxlen = 1
r = 1, l = 0
m not in map maxlen = 2, map = (t,0) (m,1)
l = 0, r = 2
m in map l = 2, map = (t,0) (m,2)
l = 2 r=3
z not in map, maxlen = 2, map = (t,0) (m,2) (z,3)
u not in map, maxlen = 3, map = (t,0) (m,2) (z,3) (u,4)
x not in map, maxlen = 4, map = (t,0) (m,2) (z,3) (u,4) (x,5)



*/
