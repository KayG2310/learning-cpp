// brute force --> 2n+nlogn, sc = 2n, this one is good to go
class Solution {
public:
    string frequencySort(string s) {
        map<int,vector<char>>freq;
        unordered_map<char,int>ini;
        for(int i=0; i<s.length(); i++){
            ini[s[i]]++;
        }
        for(auto &val:ini){
            char x = val.first;
            int y = -1*val.second;
            freq[y].push_back(x);
        }
        string final="";
        for(auto &val:freq){ //n
            vector<char>temp = val.second;
            for(int i=0; i<temp.size(); i++){
                for(int j=0; j<(-1*val.first); j++){
                    final+=temp[i];
                }
            }
        }
        return final;
    }
};

// optimal 
