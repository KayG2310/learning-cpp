#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    // our array is created, we now implement 
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        // once the inner for loop ends we have found a minimum for i
        // now we swap
        int temp = arr[i]; // 6 
        arr[i] = arr[min];
        arr[min] = temp;
    }
    // next step is verifying, i.e. displaying
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// dry run
// 1 9 3 4 6 
// i=0, min = 0 inner loop - 1 stays
// i =1, min = 1, inner loop, min = 2, temp = 6, 1 3 
