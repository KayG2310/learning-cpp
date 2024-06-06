#include<bits/stdc++.h>
using namespace std;
int numDivisible(int l,int r, vector<int> arr){
    // divisible by atleast one of the elements in array
    // atleast total - none
    int total = r-l+1;
    int none = 0;
    for(int j=l; j<=r; j++){
        // accessing elements in range
        int div=0;
        for(int i=0; i<arr.size(); i++){
            if(j%arr[i]!=0){
                //not divisible
                div++;
            }
        }
        if(div==arr.size()){
            none++;
        }
    }
    return total-none;
}
int main(){
    vector<int> v= {1,2};
    cout<<numDivisible(579000,987654,v);
}
