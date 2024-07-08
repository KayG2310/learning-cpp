// my first submission sc = 2n, tc=nlogn
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        map<char,int>one,two;
        for(int i=0; i<s.length(); i++){
            one[s[i]]++;
            two[t[i]]++;
        }
        if(one==two) return true;
        return false;
    }
};

// 2*(nlogn) +m
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t) return true;
        return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>one;
        for(int i=0; i<s.length(); i++){
            one[s[i]]++;
        }
        for(int i=0; i<s.length(); i++){
            one[t[i]]--;
            if(one[t[i]]==0) one.erase(t[i]);
        }
        if(one.size()==0) return true;
        return false;
    }
};

// tc = 2n, sc=n
