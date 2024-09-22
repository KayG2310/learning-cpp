class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>>graph(V);
        for(auto &val:edges){
            graph[val.first].push_back(val.second);
            graph[val.second].push_back(val.first);
            // graph[val.second][val.first]=1;
            
        }
        return graph;
    }
};
