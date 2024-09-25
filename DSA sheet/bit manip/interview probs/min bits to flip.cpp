class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int xorr = start^goal;
        return __builtin_popcount(xorr);
    }
};
