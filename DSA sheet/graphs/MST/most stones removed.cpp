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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        // since we do not have the dimensions of the grid
        int n=0;
        for(auto it:stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
            n++;
        }
        DisjointSet ds(maxrow+maxcol+1); // for safety
        unordered_set<int>used;
        for(auto it:stones){
            int rownode = it[0];
            int rowcol = it[1]+maxrow+1;
            ds.union_size(rownode, rowcol);
            used.insert(rownode);
            used.insert(rowcol);
        }
        int cnt =0;
        for(auto it: used){
            if(ds.ultimate_parent(it)==it) cnt++;
        }
        return n-cnt;


    }
};
