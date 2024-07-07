class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // prefix is the initial letters
        int minlen = INT_MAX, minindex = -1;
        for(int i=0; i<strs.size(); i++){
            if(strs[i].length()<minlen){
                minlen = strs[i].length();
                minindex=i;
            }
        }
      
        string ans="";
        for(int i=0; i<minlen; i++){
            char x=strs[minindex][i];
            int cnt=0;
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i]==x){
                    //ans+=x;
                    cnt++;
                }
            }
            if(cnt==strs.size()){
                ans+=x;
            }
            else return ans;
        }
        return ans;
    }
};

// tc of above code is O(n) + O(m*n) clearly not that optimal timewise, O(1) is SC

// optimised code 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        // nlogn
        // after sorting just compare the first word and the last word
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans="";
        for(int i=0; i<first.size(); i++){
            if(first[i]==last[i]){
                ans+=first[i];
            }
            else return ans;
        }
        return ans;
    }
};
