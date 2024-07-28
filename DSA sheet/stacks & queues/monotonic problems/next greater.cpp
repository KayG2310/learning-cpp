// variation - 1 this is without rotation
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,12,5,3,1,2,5,3,1,2,4,6};
    int n = sizeof(arr)/sizeof(int);
    int ans[n] = {0};
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        while(! st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}
/*
dry run
6, while no, if yes, st = 6
4, while no, if no, else yes, ans = 4,12,5,3,1,2,5,3,1,2,6,-1, st = 6 4
2, while no, if no, else yes, ans = 4,12,5,3,1,2,5,3,1,4,6,-1, st = 6 4 2
1 ans = 4,12,5,3,1,2,5,3,2,4,6,-1, st = 6 4 2 1
3, while yes, st = 6 4, if no, ans = 4,12,5,3,1,2,5,4,2,4,6,-1, st = 6 4 3
3, while yes, st = 6 4, if no, ans = 4,12,5,3,1,2,5,4,2,4,6,-1, st = 6 4 3 
*/

// variation - 2 rotation included
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {2,10,12,1,11};
    int n = sizeof(arr)/sizeof(int);
    int arrcopy[2n] = {0};
    stack<int>st;
    for(int i=0; i<2n; i++){
        arrcopy[i] = arr[i%n];
    }
    // afterwards same logic
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}
/*
dry run
6, while no, if yes, st = 6
4, while no, if no, else yes, ans = 4,12,5,3,1,2,5,3,1,2,6,-1, st = 6 4
2, while no, if no, else yes, ans = 4,12,5,3,1,2,5,3,1,4,6,-1, st = 6 4 2
1 ans = 4,12,5,3,1,2,5,3,2,4,6,-1, st = 6 4 2 1
3, while yes, st = 6 4, if no, ans = 4,12,5,3,1,2,5,4,2,4,6,-1, st = 6 4 3
3, while yes, st = 6 4, if no, ans = 4,12,5,3,1,2,5,4,2,4,6,-1, st = 6 4 3 
*/
