class DisjointSet{
    public:
    vector<int>rank, parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int>rows = {-1, 1, 0, 0};
        vector<int>cols = {0, 0, -1, 1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    for(int k=0; k<4; k++){
                        int nr = i+rows[k];
                        int nc = j+cols[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            ds.union_size(i*n+j, nr*n+nc);
                        }
                    }
                }
            }
        }
        int ans = *max_element(ds.size.begin(), ds.size.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    for(int k=0; k<4; k++){
                        int nr = i+rows[k];
                        int nc = j+cols[k];
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            st.insert(ds.ultimate_parent(nr*n+nc));
                        }
                    }
                    int m = 0;
                    for(auto it:st){
                        m+= ds.size[it];
                    }
                    ans = max(ans, m+1);
                }
            }
        }
        return ans;
    }
};
