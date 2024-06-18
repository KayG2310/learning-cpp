// probably brute force O(N) 
#include<bits/stdc++.h>
using namespace std;

int main(){
    // brute force
    int arr[5] = {1,0,2,3,0};
    // output should be {1,2,3,0,0}
    int size = sizeof(arr)/sizeof(int);
    int k = 0;
    for(int i=0; i<size;i++){
        if(arr[i] != 0){
            arr[k] = arr[i];
            k++;
        }
    }
    for(int i=k; i<size; i++){
        arr[i] = 0;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    
    
}

// optimal approach - 2 pointer approach
int j = -1
for(int i=0; i<n;i++){
  if(a[i]==0){
    j=i;
    break;
  }
}
// if j is -1 do nothing

for(int i=j+1; i<n;i++){
  if(a[i]!=0){
    swap(a[i],a[j]);
    j++;
  }
}
