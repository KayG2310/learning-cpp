class Solution {
  private:
    void topo(int node, 
    vector<vector<pair<int, int>>>&edge, 
    stack<int>&st, vector<int>&visited){
        visited[node] = 1;
        for(auto &val: edge[node]){
            int node2 = val.first;
            if(!visited[node2]){
                topo(node2, edge, st, visited);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>>edge(v);
        for(int i=0; i<e; i++){
            edge[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        // adjcacency list
        stack<int>st;
        vector<int>visited(v,0);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                topo(i, edge, st, visited);
            }
        }
        // traverse through stack
        vector<int>dist(v, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto &it: edge[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node]+wt < dist[v]){
                    // update 
                    dist[v] = dist[node]+wt;
                }
            }
        }
        for(int i=0; i<v; i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
        
    }
};
