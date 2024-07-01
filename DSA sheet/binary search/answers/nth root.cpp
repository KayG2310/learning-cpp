#include <bits/stdc++.h>
using namespace std;

int main() {
    // nth root
    // can use linear search -> simple, will work, won't ever traverse till the number itself
    int m, n;
    cin>>m>>n;
    
    int low = 1, high = m, mid = 0;
    bool flag = true;
    while(low<=high){
        mid = (low+high)/2;
        if(pow(mid,n)==m){
            flag = false;
            return mid;
        }
        else if(pow(mid,n)>m) high = mid-1;
        else low = mid+1;
    }
    if(flag) return -1;
}

// can be made to avoid overflow by using breaks instead of pow(mid,n)
