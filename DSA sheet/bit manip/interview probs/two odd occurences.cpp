class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        long xorr = 0;
        for(int i=0; i<N; i++){
            xorr = xorr^arr[i];
        }
        // xorr of answers is left
        long rightmost = (xorr&(xorr-1))^xorr;
        long b1 = 0, b2 = 0;
        for(int i=0; i<N; i++){
            if((arr[i]&rightmost) !=0){
                b1 = b1^arr[i];
            }
            else{
                b2 = b2^arr[i];
            }
        }
        if(b2>b1) swap(b1,b2);
        return {b1,b2};
    }
};

// tc = 2n, sc = 1
