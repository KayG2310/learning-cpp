#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v= {{1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}};
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j< v.size(); j++){
            if(i != j){
                swap(v[i][j], v[j][i]);
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        reverse(v[i].begin(), v[i].end());
        for(int j=0; j< v.size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
