#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<= high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    
    // Copy sorted elements back to the original vector
    for (int i = low; i <= high; i++) {
        v[i] = temp[i - low];
}
}
void merge_sort(vector<int> &v, int low, int high){
    if(low>=high){
        return;
    }
    int mid;
    mid = (low+high)/2;
    merge_sort(v, low, mid);
    merge_sort(v, mid+1, high);
    merge(v,low,mid,high);
    
}
int main() {
    vector<int> v = {5,8,4,3,9};
    merge_sort(v, 0, v.size()-1);
    for(auto &value: v){
        cout<<value<<" ";
    }
}


