#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& nums) {
    int n = nums.size();
    int count=0;
    map<int,int> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            m[(nums[i]& nums[j])]++;
            }
        }
    
 
       for(int k = 0; k<n; k++){
        for(auto &it : m){
            if((nums[k]&it.first)==0){
                count+=it.second;
            }
        }
        
    } 
    
   
    return count;
 
}

int main(){
    vector<int>v = {0,0,0};
    cout<<countTriplets(v);
}
