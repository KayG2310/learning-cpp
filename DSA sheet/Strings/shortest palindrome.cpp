class Solution {
private:
    vector<int> lps(string &s) {
        int n = s.size();
        vector<int> p(n, 0); // Longest prefix suffix (LPS) array
        for (int i = 1; i < n; i++) {
            int j = p[i - 1]; // Start with the previous LPS length
            while (j > 0 && s[i] != s[j]) {
                j = p[j - 1]; // Fallback to the previous LPS
            }
            if (s[i] == s[j]) {
                p[i] = j + 1; // Increment LPS length if characters match
            }
        }
        return p;
    }

public:
    string shortestPalindrome(string s) {
        if (s.empty()) return ""; // Handle empty string

        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end()); // Reverse the string

        string combined = s + '$' + reversed_s; // Concatenate s + '$' + reversed_s
        vector<int> p = lps(combined); // Compute LPS array for the combined string

        int matched = p.back(); // Longest prefix that matches a suffix
        string to_add = s.substr(matched); // Get the unmatched part
        reverse(to_add.begin(), to_add.end()); // Reverse it to prepend
        return to_add + s; // Prepend and return the result
    }
};
