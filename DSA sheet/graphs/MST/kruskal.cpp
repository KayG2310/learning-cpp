class DisjointSet{
    vector<int>rank, parent, size;

    public:
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<vector<int>>graph;
        for(int i=0; i<v; i++){
            // parent[i] = i;
            for(auto &it: adj[i]){
                graph.push_back({it[1], i, it[0]});
            }
        }
        sort(graph.begin(), graph.end());
        DisjointSet ds(v);
        int mst = 0;
        for(auto it:graph){
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            if(ds.ultimate_parent(u)!=ds.ultimate_parent(v)){
                mst += wt;
                ds.union_size(u, v);
            }
        }
        return mst;
        
    }
}; 
