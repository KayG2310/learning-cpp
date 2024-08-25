// q link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// brute force technique - generate all substrings. tc = n^2, sc = 1
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            vector<int> hash(3,0);
            for(int j=i; j<s.length(); j++){
                hash[s[j]-'a'] = 1;
                if(*min_element(hash.begin(), hash.end())==1) cnt++;
            }
        }
        return cnt;
    }
};

//optimal
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        vector<int> hash(3,-1);
        for(int i=0; i<s.length(); i++){
                hash[s[i]-'a'] = i;
                if(hash[0] !=-1 && hash[1] !=-1 && hash[2] !=-1){
                    cnt+=(1+min(hash[0], min(hash[1], hash[2])));
                } 
            
        }
        return cnt;
    }
};
