class Solution {
public:
    int rangeBitwiseAnd(long long left, long right) {
    while(left<right){
        right = right & (right-1);
    }
    return left & right; 
    }
};
