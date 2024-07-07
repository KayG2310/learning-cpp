class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,vector<int>>one, two;
        for(int i=0; i<s.length(); i++){
            one[s[i]].push_back(i);
            two[t[i]].push_back(i);
        }
        //O(n)
        if(one.size()!=two.size()){
            return false;
        }
        vector<vector<int>>ones, twos;
        for(auto &val:one){
            ones.push_back(val.second);
        }
        //O(n)
        for(auto &val:two){
            twos.push_back(val.second);
        }
        // o(n)
        sort(ones.begin(), ones.end()); // O(nlogn)
        sort(twos.begin(), twos.end());
        if(ones==twos) return true;
        return false;
        //3n + 2(nlogn)
    }
};
