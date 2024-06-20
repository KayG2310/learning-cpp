// brute force - check the appearance of each using nested for loop
// better create a hash map
// create an unordered map is better
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[12] = {0,1,2,0,1,2,1,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(int);
    unordered_map<int,int>freq;
    for(int i=0; i<n;i++){
        freq[arr[i]]++;
    }
    for(auto &val: freq){
        if(val.second>n/2){
            cout<<val.first<<" ---> "<<val.second<<" times";
            break;
        }
    }
}
// submitted on leetcode

// optimal approach - Moore's Voting Algorithm
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[12] = {0,1,2,0,1,2,1,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(int);
    int cnt = 0;
    int el;
    for(int i=0; i<12;i++){
        if(cnt==0){
            cnt=1;
            el = arr[i;]
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
        
    }
    int cnt1=0;
    for(int i=0; i<n;i++){
        if(arr[i]==el){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        cout<<el;
    }
    else{
        cout<<-1;
    }
}
