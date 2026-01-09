#include<bits/stdc++.h>
using namespace std;

int main(){
    // intersection of two sorted arrays using the same two pointer approach
    int arr1[5] = {10,20,30,40,70};
    int arr2[6] = {40,70,80,90,100,110};
    vector<int> intersection;
    int i=0, j=0;
    while(i<5 && j<6){
        if(arr1[i]<arr[j]){
            // if the first element is smaller, it cannot even have itself in arr 2
            i++;
        }
        else if(arr2[j] < arr1[i]){
            // j cannot have a partner in array 1
            j++;
        }
        else{
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        
    }
    // ans is formed
}
