#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    // array is created
    for(int i=0; i<n;i++){
        int j = i;
        // since we are going from index 0 to n-1
        // you go towards the left till i-1
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
        
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}

// 78 34 67 23 69 32 3
// i = 0
    // no change, array as it is
// i = 1
    // while satisfied
        // 34 78 67 23 69 32 3
// i =2
    // while satisfied
        // 34 67 78 23 69 32 3, j = 1, while no
// i = 3
    // 34 67 23 78 69 32 3, j=2
    // 34 23 67 78 69 32 3, j=1
    // 23 34 67 78 69 32 3
// i = 4
    // so on
