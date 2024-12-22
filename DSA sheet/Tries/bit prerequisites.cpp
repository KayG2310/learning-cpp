class Solution {
  public:
    int XOR(int n, int m) {
        // code here
        return n ^ m;
    }
    int check(int a, int b) {
        // code here
        return (b>>(a-1))&1;
    }
    int setBit(int c, int d) {
        // code here
        return (1<<c) | d;
    }
};
