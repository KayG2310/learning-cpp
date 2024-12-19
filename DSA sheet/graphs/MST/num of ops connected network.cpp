class DisjointSet{
    
    public:
    vector<int>parent, size;
    DisjointSet(int n){
        // rank.resize(n, 0);
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.ultimate_parent(u)==ds.ultimate_parent(v)) extras++;
            else(ds.union_size(u, v));
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i) comp++;
        }
        if(extras>=comp-1) return comp-1;
        return -1;
    }
};
