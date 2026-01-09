// brute force
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[4] = {3,4,5,6};
    int arr2[3] = {1,2,3};
    unordered_set<int> s;
    for(int i=0; i<4;i++){
        s.insert(arr[i]);
    }
    for(int i=0; i<3;i++){
        s.insert(arr2[i]);
    }
    
    // push the set elements into an array
    
}

// optimal 

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0, j=0;
        vector<int>ans;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                if(ans.size()==0|| ans.back() != arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            else{
                if(ans.size()==0||ans.back() != arr2[j]){
                    ans.push_back(arr2[j]);
                    
                }
                j++;
            }
        }
        while(i<n){
            if(ans.size()==0||ans.back() != arr1[i]){
                    ans.push_back(arr1[i]);
                }
                i++;
        }
        while(j<m){
            if(ans.size()==0||ans.back() != arr2[j]){
                    ans.push_back(arr2[j]);
                }
                j++;
        }
        return ans;
    }
