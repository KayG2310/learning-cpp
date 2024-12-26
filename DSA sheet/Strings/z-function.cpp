class Solution {
public:
    void zFunction(vector<int>& z, string& zString) {
        int left = 0;
        int right = 0;
        z[0] = 0;
        for (int i = 1; i < z.size(); i++) {
            if (i > right) {
                right = i;
                left = i;

                while (right < zString.length() &&
                       zString[right] == zString[right - left]) {
                    right++;
                }

                z[i] = right - left;
                right -= 1;

            } else {
                int i1 = i - left;

                if (z[i1] < right - i + 1) {
                    z[i] = z[i1];
                } else {
                    left = i;
                    while (right < zString.length() &&
                           zString[right] == zString[right - left]) {
                        right += 1;
                    }
                    z[i] = right - left;
                    right -= 1;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int ans = 0;

        string zString = needle + "$" + haystack;

        vector<int> z(zString.length(), 0);

        zFunction(z, zString);

        for (int i = 0; i < z.size(); i++) {
            if (z[i] == needle.length()) {
                ans = i - (needle.length() + 1);
                return ans;
            }
        }

        return -1;
    }
}; 
tc O(m+n) sc = 1
