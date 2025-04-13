#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int>ans(n, -1);
    // setting everything by default to -1
    stack<int>nse;
    for(int i=n-1; i>=0; i--){
        while(!nse.empty() && nse.top()>=arr[i]){
            nse.pop();
        }
        if(!nse.empty()){
            ans[i] = nse.top();
        }
        nse.push(arr[i]);
    }
    return ans;
}
