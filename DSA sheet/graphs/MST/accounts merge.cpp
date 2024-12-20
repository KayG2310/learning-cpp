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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int>mpp;
        for(int i=0; i<n; i++){
            for(auto it:accounts[i]){
                if(it==accounts[i][0]) continue;
                if(mpp.find(it) == mpp.end()) mpp[it]=i;
                else ds.union_size(i, mpp[it]);
            }
        }
        vector<vector<string>>ans(n);
        for(auto it : mpp){
            string mail = it.first;
            int node = it.second;
            int par = ds.ultimate_parent(node);
            ans[par].push_back(mail);
        }
        vector<vector<string>>finals;
        for(int i=0; i<n; i++){
            if(ans[i].size()==0) continue;
            sort(ans[i].begin(), ans[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:ans[i]){
                temp.push_back(it);
            }
            finals.push_back(temp);
        }
        return finals;

    }
};
