class Solution {

private:
    void dfs(int i, string path, long res, long prev, string &s, int target, vector<string>&ans) {
        if (i == s.length()) {
            if (res == target) ans.push_back(path);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (j > i && s[i] == '0') break; 
            string cur = s.substr(i, j - i + 1);
            long currNum = stol(cur); // Convert substring to long

            if (i == 0) {
                // First number, pick it without adding any operator
                dfs(j + 1, path + cur, currNum, currNum, s, target, ans);
            } else {
                // Add operator '+'
                dfs(j + 1, path + "+" + cur, res + currNum, currNum, s, target, ans);
                // Add operator '-'
                dfs(j + 1, path + "-" + cur, res - currNum, -currNum, s, target, ans);
                // Add operator '*'
                dfs(j + 1, path + "*" + cur, res - prev + prev * currNum, prev * currNum, s, target, ans);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        dfs(0, "", 0, 0, num, target, ans);
        return ans;
    }
}; 
