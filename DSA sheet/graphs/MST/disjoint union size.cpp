#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1); // every independently includes itself 
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
    void union_size(int node1, int node2){
        int u1 = ultimate_parent(node1);
        int u2 = ultimate_parent(node2);
        if(u1 == u2){
            return;
        }
        // else 
        int s1 = size[u1];
        int s2 = size[u2];
        if(s1<s2){
            parent[u1] = u2;
            size[u2]+=size[u1];
        }
        else if(s2<s1){
            parent[u2] = u1;
            size[u1]+=size[u2];
        }
        else{
            // they are the same rank
            parent[u2] = u1;
            size[u1]+=size[u2];
        }
    }
};
int main(){
    DisjointSet d(7);
    d.union_size(1,2);
    d.union_size(2,3);
    d.union_size(4,5);
    d.union_size(6,7);
    d.union_size(5,6);
    if(d.ultimate_parent(3)==d.ultimate_parent(7)){
        cout<<"same"<<endl;
        
    }
    else cout<<"not same"<<endl;
    d.union_size(3,7);
    if(d.ultimate_parent(3)==d.ultimate_parent(7)){
        cout<<"same"<<endl;
        
    }
    else cout<<"not same"<<endl;
}
