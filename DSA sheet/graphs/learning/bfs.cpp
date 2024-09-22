class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        int visited[V] = {0};
        visited[0] = 1;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int x = q.front();
            for(auto &val:adj[x]){
                if(visited[val]==0){
                    q.push(val);
                    visited[val]=1;
                }
            }
            q.pop();
            ans.push_back(x);
        }
        return ans;
    }
};
