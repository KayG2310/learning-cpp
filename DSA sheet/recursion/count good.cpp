const int mod = 1e9+7;
class Solution {
private:
    long long myPow(long long x, long long n) {
        long long ans = 1.0;
        long long nn = n;
        while(nn){
            if(nn%2==0){
                x = ((x%mod)*(x%mod))%mod;
                nn = nn/2;
            }
            else{
                ans = ((ans%mod)* (x%mod))%mod;
                nn -=1;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long even = ceil(n/2.0);
        long long odd = floor(n/2.0);
        if(odd == 0) return 5;
        long long x = myPow(5, even)%mod;
        long long y = myPow(4, odd)%mod;
        return (x*y)%mod;
    }
};
