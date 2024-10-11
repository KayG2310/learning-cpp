class Solution {
public:
    void f(int index, string &ds, vector<string>&ans, unordered_map<char, vector<char>>&m, string &digits){
        if(index == digits.length()){
              ans.push_back(ds);
                return;
        }

        for(auto p: m[digits[index]]){
            ds += p;
            f(index+1, ds, ans, m, digits);
            ds.pop_back();
        }
        }
    vector<string> letterCombinations(string digits) {
        if(digits == "" || digits == "1") return {};
        unordered_map<char, vector<char>>m;
        m['1'] = {};
        m['2'] = {'a', 'b','c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        string ds = "";
        vector<string>ans;
        f(0, ds, ans, m, digits);
        return ans;
    }
};
