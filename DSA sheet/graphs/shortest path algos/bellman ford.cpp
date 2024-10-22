class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        // Code here
        int e = edges.size();
        vector<int>dist(v, 1e8);
        dist[src] = 0;
        for(int i=1; i<v; i++){
            for(int j=0; j<e; j++){
                int start = edges[j][0];
                int end = edges[j][1];
                int wt = edges[j][2];
                if(dist[start] == 1e8) continue;
                if(dist[start]+wt<dist[end]){
                    dist[end] = dist[start]+wt;
                }
            }
        }
        bool flag = false;
        for(int j=0; j<e; j++){
            int start = edges[j][0];
            int end = edges[j][1];
            int wt = edges[j][2];
            if(dist[start] == 1e8) continue;
            if(dist[start]+wt<dist[end]){
                dist[end] = dist[start]+wt;
                flag = true; break;
            }
        }
        if(flag){
            return {-1};
        }
        return dist;
    }
};
