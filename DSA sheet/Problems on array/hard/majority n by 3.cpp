// leetcode brute force submission O(
#include<bits/stdc++.h>
using namespace std;

int main(){
    // brute force 
    int arr[] = {1,1,1,3,3,2,2,2};
    int n = sizeof(arr)/sizeof(int);
    vector<int> ans;
    for(int i=0; i<n;i++){
        if(ans.find(arr[i]) == ans.end()){
            int cnt =1;
            for(int j = i+1; j<n;j++ ){
                if(arr[j]==arr[i]){
                    cnt++;
                }
            }
            if(cnt>n/3){
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}

// optimal --> extension of moore's voting algorithm
#include<bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &v){
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(cnt1 == 0 && el2 != v[i]){
            cnt1 = 1;
            el1 = v[i];
        }
        else if(cnt2 == 0 && el1 != v[i]){
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i]==el1) cnt1++;
        else if(v[1]==el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    // reinitialize cnt1 and cnt2 and do a manual check before putting them into an array
}
