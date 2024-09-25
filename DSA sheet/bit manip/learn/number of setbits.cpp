// gfg question 
// appraoch 1 : builtin_popcount;
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int s = 0;
        for(int i=1; i<=n; i++){
            s+= __builtin_popcount(i);
        }
        return s;
    }
};

// approach 2
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int s = 0;
        for(int j=1; j<=n; j++){
            int i=j;
            int cnt = 0; 
            while(i>0){
                cnt+= (i&1);
                i = i>>1;
            }
            cnt+= (i&i);
            s+=cnt;
        }
        return s;
    }
};

// approach 3
// while (n!=0){ n = n&n-1; cnt++;}
