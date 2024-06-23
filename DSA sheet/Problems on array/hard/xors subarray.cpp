#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > nums, int k) {
    int n = nums.size();
    int cnt = 0;
    long long xors = 0;
    unordered_map<long long,int> m;
    m[xors]++;
    for(int i=0; i<n;i++){
        xors = xors^ nums[i];
        long long x = xors^k;
        cnt+=m[x];
        m[x]++;
        
    }
    return cnt;
}
