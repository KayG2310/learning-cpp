class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
      // 0 based indexing
        vector<vector<int>>graph(V, vector<int>(V,0));
        for(auto &val:edges){
            graph[val.first][val.second]=1;
            graph[val.second][val.first]=1;
            
        }
        return graph;
    }
};
