class Solution {
  private:
    void f(vector<vector<int>>&edge, vector<int>&dist, queue<pair<int,int>>&q){
        while(q.empty()==false){
            auto p =q.front();
            q.pop();
            int node = p.first;
            int d = p.second;
            if(dist[node] > d) dist[node] = d;
            for(auto &val: edge[node]){
                if(dist[val] == INT_MAX){
                    // not yet visited
                    // dist[val] = d+1; 
                    q.push({val, d+1});
                }
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src){
        vector<vector<int>>edge(n);
        for(int i=0; i<m; i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        // adjacency list 
        queue<pair<int,int>>q;
        q.push({src, 0});
        
        vector<int>distances(n, INT_MAX);
        distances[src] = 0;
        f(edge, distances, q);
        for(int i=0; i<n; i++){
            if(distances[i] == INT_MAX) distances[i] = -1;
            // cout<<distances[i]<<" ";
        }
        return distances;
    }
};
