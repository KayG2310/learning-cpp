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
    // this is what inner loop will look like
    for(int i=n-1; i>=0;i--){
        bool swap = true;
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = false;
            }
        }
        if(swap) break; 
        for(int k=0; k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    
}
