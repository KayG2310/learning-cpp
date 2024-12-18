class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // step 1 : creating adjcacency list 
        vector<vector<vector<int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            auto it = flights[i];
            int from = it[0];
            int to = it[1];
            int cost = it[2];
            adj[from].push_back({to, cost});
        }
        queue<vector<int>>q;
        q.push({0, src, 0});
        // stops, source, distance
        vector<int>dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            int node = it[1];
            int stops = it[0];
            int cost = it[2];
            q.pop();
            if(stops > k) continue;
            for(auto iter:adj[node]){
                int neighnode = iter[0];
                int ew = iter[1];
                if(cost+ew<dist[neighnode] && stops <= k){
                    dist[neighnode] = cost+ew;
                    q.push({stops+1, neighnode, cost+ew});
                }
            }
        }


        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};
