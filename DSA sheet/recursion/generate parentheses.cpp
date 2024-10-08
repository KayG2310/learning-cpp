class Solution {
public:
    void generate(string &s, int open, int close, vector<string>&res){
        if(open == 0 && close == 0){
            res.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            generate(s, open-1, close, res);
            s.pop_back();
        }
        if(close>0 && open<close){
            s.push_back(')');
            generate(s, open, close-1,res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result ;
        if(n==1) return {"()"};
        string s = "";
        generate(s, n, n, result);
        return result;
    }
};
