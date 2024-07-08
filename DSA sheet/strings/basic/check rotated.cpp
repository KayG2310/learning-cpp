class Solution {
public:
    bool rotateString(string s, string goal) {
        int k=1;
        if(s==goal) return true;
        while(k<=s.size()){
            char temp=s[0];
            for(int i=1; i<s.size(); i++){
                s[i-1] = s[i];
            }
            s[s.size()-1]=temp;
            if(s==goal) return true;
            k+=1;
        }
        return false;
    }
};

// above can take O(n2) 0ms on leetcode
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string f=s+s; //abcdabcd
        int found = f.find(goal);
        if(found==-1) return false;
        return true;
    }
};

