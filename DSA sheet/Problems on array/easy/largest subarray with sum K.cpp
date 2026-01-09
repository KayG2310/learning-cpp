// better approach using cumulative sums
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    int size = sizeof(arr)/sizeof(int);
    map<long long, int> presum;
    long long sum = 0;
    int len = 0; //len of subarray
    // subarrays are contiguous
    for(int i=0; i<size;i++){
        sum+=arr[i];
        if(sum==k){
            len = max(len, i+1);
        }
        long long remaining = sum - k;
        if(presum.find(remaining) != presum.end()){
            int leny =  i - presum[remaining];
            len = max(len, leny);
        }
      if(presum.find(sum) == presum.end()){
        presum[sum] = i;
      }
    }
    cout<< len;
    // presum = {{1,0}, {3,1}, {6,2}, {4,3}, {5,4}, {9,5},  }
}
// i=0 sum = 1 no if, rem = 1-3 = -2, 
// i = 1, sum = 3, if yes, len = 2, rem = 3-3=0
// i = 2, sum = 6, if no, rem = 3, if no,
// i = 3, sum = 7, if no, rem = 4, if no,
// i = 4, sum = 8, if no, rem = 5, 
// i = 5, sum = 9, if no, rem = 6, if yes, leny = 5-2 = 3, len = 3




// a1, a2, a3,.aq...al,....am,.....ap....an
// map mei sum till q, index q
// a1+a2+..aq, aq+1+....ap-k = a1+a2+....aq





---------------------------------------------------------
  
