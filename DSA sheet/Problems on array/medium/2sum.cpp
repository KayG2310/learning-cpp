// brute force
#include<bits/stdc++.h>
using namespace std;

int main() {
    int k=15;
    int arr[5] = {2,6,5,8,11};
    bool flag = false;
    for(int i=0; i<5;i++){
        int sum = arr[i];
        for(int j=i+1; j<5;j++){
            if(sum+arr[j]==k){
                cout<<"yes";
                flag = true;
                break;
            }
        }
        if(flag==true){
            break;
        }
    }
    cout<<flag;
}

// better 
#include<bits/stdc++.h>
using namespace std;

int main() {
    int k=15;
    int arr[5] = {2,6,5,8,11};
    unordered_map<int,int> mp;
    for(int i=0; i<n;i++){
        int a = arr[i];
        int rem = k-a;
        if(mp.find(rem) != mp.end()){
            cout<<"yes";
            cout<<endl<<i<<" "<<mp[rem];
        }
        mp[a] = i;
    }
    //can put flag or put return statements
}
