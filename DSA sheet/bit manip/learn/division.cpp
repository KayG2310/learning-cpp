class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend<0 && divisor>0) sign = false;
        if(dividend>0 && divisor<0) sign = false;

        long n = abs(dividend);
        long y = abs(divisor);
        long q = 0;
        while(n>=y){
            int cnt = 0;
            while(n>=y<<(cnt+1)){
                cnt++;
            }
            q += 1<<cnt;
            n -= (y<<cnt);
        }
        if(q == (1<<31) && sign) return INT_MAX;
        if(q == (1<<31) && !sign) return INT_MIN;
        return sign?q:-q;

    }
};
