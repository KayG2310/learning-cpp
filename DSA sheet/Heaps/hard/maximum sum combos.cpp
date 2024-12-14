#include<bits/stdc++.h>

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>ans;
    // heap to store sum
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    priority_queue<vector<int>>pq;
    pq.push({A[n-1]+B[n-1], n-1, n-1});
    // initialized
    set<pair<int, int>>s;
    s.insert({n-1, n-1});
    while(C--){
        vector<int>top = pq.top();
        ans.push_back(top[0]);
        pq.pop();
        if(top[1]-1 >=0 && s.find({top[1]-1, top[2]}) == s.end() ) {
            pq.push({A[top[1]-1]+B[top[2]], top[1]-1, top[2]});
            s.insert({top[1]-1, top[2]});
        }
        if(top[2]-1 >=0 && s.find({top[1], top[2]-1}) == s.end()) {
            pq.push({A[top[1]]+B[top[2]-1], top[1], top[2]-1});
            s.insert({top[1], top[2]-1});
        }
        
    }
    return ans;
}
 
