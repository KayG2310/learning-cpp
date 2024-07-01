// most obvious approach --->
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int ans = pow(x,0.5);
        return ans;
    }
};

// using binary search 
#include <bits/stdc++.h>
using namespace std;

int main() {
    // return floor of sqrt of given number
    // most common way -->
    int n;
    cin>>n;
    
    int low = 1, high = n, mid = 0;
    while(low<=high){
        mid = (low+high)/2;
        if(mid*mid<=n && (mid+1)*(mid+1)>n){
            cout<<mid;
            break;
        }
        else if(mid*mid>n){
                high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}
// dry run 
/*
n = 35
low = 1, high = 35, mid = 18
324 > 35, high = 17
mid = 9
81>35, high = 8
mid = 4
16<35 and 25<35nope, low = 5 mid = 6 high = 8
high = 7 low = 5
mid = 6
high = 5 mid = 5 yess


*/

// take care on stack overflow condition when you multiply number by itself
