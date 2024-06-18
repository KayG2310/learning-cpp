#include<bits/stdc++.h>
using namespace std;

int main(){
    // brute force technique 
    int arr[7] = {1,2,3,4,5,6,7};
    int k;
    int size = sizeof(arr)/sizeof(int);
    cin>>k;
    k = k%size;
    for(int i=0; i<k;i++){
        int temp = arr[0];
        for(int j=1; j<size;j++){
            arr[j-1] = arr[j];
        }
        arr[size-1] = temp;
    }
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    // time complexity = k*(n-1)
    // not ideal, can give time complexity
    // important guideline, number of rotations will be k%size
    // eg we have size 7 and rotations 8, effectively rotations are 1
    
    // optimal solution which avoids multiplication of kn
    cout<<endl;
    int arr2[7] = {10,20,30,40,50,60,70};
    int size2 = sizeof(arr2)/sizeof(int);
    int temp2[k];
    for(int i=0; i<k;i++){
        temp2[i] = arr2[i];
    }
    for(int i=k; i<size2; i++){
        arr2[i-k] = arr2[i];
    }
    
    // time for insertion of temp
    // array has been filled with n-k elements 
    for(int i=0; i<k;i++){
        arr2[size2-k+i] = temp2[i];
    }
    
    //display
    for(int i=0; i<size2;i++){
        cout<<arr2[i]<<" ";
    }
    
}
