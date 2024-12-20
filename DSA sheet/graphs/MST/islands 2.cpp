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
  private:
    bool valid(int n, int m, int nr, int nc){
        if(nr>=0 && nc>=0 && nr<n && nc<m) return true;
        return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt =0;
        vector<int>ans; // stores the 
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        for(auto it: operators){
            int r = it[0];
            int c = it[1];
            if(vis[r][c]) {
                ans.push_back(cnt); // no change
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            for(int i=0; i<4; i++){
                int nr = r+ row[i];
                int nc = c+ col[i];
                if(valid(n, m, nr, nc)){
                    if(vis[nr][nc]){
                        int node2 = nr*m+nc;
                        int node1 = r*m + c;
                        // neighbour is an island
                        if(ds.ultimate_parent(node1) != ds.ultimate_parent(node2)){
                            cnt--;
                            ds.union_size(node1, node2);
                        }
                        
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        
        return ans;
    }
};
