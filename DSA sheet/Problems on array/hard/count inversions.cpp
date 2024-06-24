// brute force approach ---> will give tle
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5,3,2,4,1};
    int n = sizeof(arr)/sizeof(int);
    int total = 0;
    for(int j=0; j<n; j++){
        for(int i=0; i<j; i++){
            if(arr[i]>arr[j]){
                total++;
            }
        }
    }
    cout<<total;
    
}

