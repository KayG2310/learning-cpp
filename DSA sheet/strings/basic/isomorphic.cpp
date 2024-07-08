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


// using string replace --> does not work
// two maps
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>stot,ttos;
        for(int i=0; i<s.length(); i++){
            if(stot.find(s[i])==stot.end()){
                stot[s[i]] = t[i];
            }
            else{
                if(stot[s[i]]==t[i]) continue;
                else return false;
            }
        }
        for(int i=0; i<t.length(); i++){
            if(ttos.find(t[i])==ttos.end()){
                ttos[t[i]] = s[i];
            }
            else{
                if(ttos[t[i]]==s[i]) continue;
                else return false;
            }
        }
        return true;

    }
};
//O(N), sc = O(2n)

