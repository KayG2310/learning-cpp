// left rotate by one place 1 2 3 4 5 --> 2 3 4 5 1
// if the element is at ith index place it at i-1
// rotate by one place code

// if it is a user inputted array
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n];
    int temp;
    cin>>temp;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    arr[n-1] = temp;
}

// as a function
void left(int arr[], int size) {
    int temp = arr[0]; 
    for (int i = 1; i < size; ++i) {
        arr[i - 1] = arr[i];
    }
    arr[size - 1] = temp;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
