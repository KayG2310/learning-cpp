// leetcode question
#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
    map<int, int> m;
    for(int i = 0; i<candies.size();i++){
        int k = candies[i];
        m[k]++;
    }
    int size= m.size();
    int caneat = candies.size()/2;
    int types = 0;
    if(caneat>=size){
        types = size;
    }
    else {
        types = caneat;
    }
    return types;
}

int main(){
    vector<int> v = {1,1,2,2,3,3};
   cout<<distributeCandies(v);
}

