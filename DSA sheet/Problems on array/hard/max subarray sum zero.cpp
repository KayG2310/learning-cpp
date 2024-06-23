#include<bits/stdc++.h>
using namespace std;

int main() {
    int nums[] = {1,-1,3,2,-2,-8,1,7,10,23};
    int n = sizeof(nums)/sizeof(int);
    unordered_map<int,int> hashmap;
    int len = INT_MIN;
    int sum = 0;
    for(int i=0; i<n;i++){
        sum += nums[i];
        if(sum==0){
            len = i+1;
        }
        else{
            int rem = sum;
            if(hashmap.find(rem) != hashmap.end()){
                // meaning the sum already exists
                len = max(len, i-hashmap[rem]);
            }
            else {
                hashmap[sum] = i;
            }
        }
    }
    cout<<len;
}
/*
// dry run 
// sum = 1 --> if no --> else, if no, map = {{1,0}, {0,1}}
sum = 0, len = 2,
sum = 3 if no, else, 
*/
