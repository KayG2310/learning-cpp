#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank, parent;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int ultimate_parent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = ultimate_parent(parent[node]);
    }
    void union_rank(int node1, int node2){
        int u1 = ultimate_parent(node1);
        int u2 = ultimate_parent(node2);
        if(u1 == u2){
            return;
        }
        // else 
        int r1 = rank[u1];
        int r2 = rank[u2];
        if(r1<r2){
            parent[u1] = u2;
        }
        else if(r2<r1){
            parent[u2] = u1;
        }
        else{
            // they are the same rank
            parent[u2] = u1;
            rank[u1]++;
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.union_rank(1,2);
    ds.union_rank(2,3);
    ds.union_rank(4,5);
    ds.union_rank(6,7);
    ds.union_rank(5,6);
    if(ds.ultimate_parent(3)==ds.ultimate_parent(7)){
        cout<<"same"<<endl;
        
    }
    else cout<<"not same"<<endl;
    ds.union_rank(3,7);
    if(ds.ultimate_parent(3)==ds.ultimate_parent(7)){
        cout<<"same"<<endl;
        
    }
    else cout<<"not same"<<endl;
}
