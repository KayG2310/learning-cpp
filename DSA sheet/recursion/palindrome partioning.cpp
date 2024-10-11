class Solution {
public:
    bool pal(string s){
        int i=0, j= s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int index, string &s, vector<vector<string>>&ans, vector<string>&ds){
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<s.length(); i++){
            string x = s.substr(index, i-index+1);
            if(pal(x)==true){
                ds.push_back(x);
                f(i+1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        f(0, s, ans,ds);
        return ans;
    }
};
