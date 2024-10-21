class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int>dist(n, 1e9);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // go to neighbours
            for(auto it: adj[node]){
                int ew = it.second;
                int no = it.first;
                if(dis+ew < dist[no]){
                    dist[no] = dis+ew;
                    pq.push({dist[no], no});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
        
        
    }
};
