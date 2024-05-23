#include<bits/stdc++.h>
using namespace std;
bool shouldswap(pair<int,int>a, pair<int,int>b){
    if(a<b) return true; // change in this condition can give us increasing or decreasing or any other conditions in pair
    return false;
}
int main(){
    int n;
    cin>>n;
    
    vector<pair<int,int>>v(n);
    for(int k=0; k<n; k++){
        cin>>v[k].first>>v[k].second;
    }
    // 4 5 2 25 7 8
    // v[i] = 4, v[j] = 5,2,25,7,8
    // 4<5, 5 comes before, v[i]=
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++ ){
            if(shouldswap(v[i], v[j])){
                swap(v[i], v[j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    
}
