#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {4, 8, 15, 16, 27, 34, 42,46,50};
    int num, end, mid, index, check,start;
    num = 42;
    end = v.size();
    start = 0;
    index = -1;
    int count = 0;
    /*loop runs
    start = 0, end = 9, mid = 4, check = 3
    16 < 42
    start = 4, end = 9, mid = 6, check = 5 {27,34,42,46,50}
    42 == 42*/
    while(index==-1){
        mid = (start+end)/2;
        check = mid -1;
        count++;
        if(v[check]==num){
            index = check;
            break;
        } else if(v[check]> num){
            // we have to discard right side
            end = check-1;
        } else if (v[check]<num){
            // we discard the left side
            start = check+1;
        } else{
            continue;
        }
        if(end==start){
            break;
        }
    }
    cout<<"found at index: "<< index<<endl<<"steps taken: "<<count;
}
