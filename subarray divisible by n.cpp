#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> nums){
    vector <int> cf;
    cf[0]=nums[0];
    for(int i=1;i<n;i++){
        cf[i]=cf[i-1]+nums[i];
    }
    map <int,int> m;
    for(int x:cf){
        if(m.count(x%n)!=1){
            m[x%n]=1;
        }
        else m[x%n]++;
    }
    int count = m[0];
    for(int i=1;i<n;i++){
        count+=m[i]*(m[i]-1)/2;//nc2
    }
    return count;
}
