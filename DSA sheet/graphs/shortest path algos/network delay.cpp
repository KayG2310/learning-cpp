class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<times.size(); i++){
            auto it = times[i];
            int start = it[0];
            int end = it[1];
            int wt = it[2];
            adj[start].push_back({end, wt});
        }
        // adjcacency list created
        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it[1];
            int d = it[0];
            pq.pop();
            for(auto iter: adj[node]){
                if(d+iter.second < dist[iter.first]){
                    dist[iter.first] = d+iter.second;
                    pq.push({d+iter.second, iter.first});
                }
            }
        }
        int sum = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i]==1e9) return -1;
            if(dist[i]==0) continue;
            sum = max(sum, dist[i]);
        }
        return sum;

    }
}; 
