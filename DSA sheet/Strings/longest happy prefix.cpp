class Solution {
public:
    int computeLPS(string& s) {
        vector<int> p(s.size(), 0); // Initialize the LPS array with 0s
        for (int i = 1; i < s.size(); i++) {
            int j = p[i - 1]; // Get the LPS value of the previous position
            if (s[j] == s[i]) {
                p[i] = j + 1; // If characters match, increment LPS value
                continue;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = p[j - 1]; // Fallback to the previous LPS value
                }
                if (s[i] == s[j]) {
                    p[i] = j + 1; // If characters match after fallback, update LPS
                }
            }
        }
        return p[s.size() - 1]; // Return the last value in the LPS array
    }

    string longestPrefix(string s) {
        return s.substr(0, computeLPS(s));
    }
};
