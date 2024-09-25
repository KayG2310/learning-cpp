class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        bool ans;
        int x = n&(1<<k);
        ans = x?true:false;
        return ans;
    }
};
