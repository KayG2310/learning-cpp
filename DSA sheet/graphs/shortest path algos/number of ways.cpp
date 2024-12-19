#define pii pair<long long, long long>
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<int>ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            pii p = pq.top();
            pq.pop();
            int node = p.second;
            long long di = p.first;
            for(auto it:adj[node]){
                int iter = it.first;
                long long ew = it.second;
                if(di+ew<dist[iter]){
                    dist[iter] = di+ew;
                    pq.push({di+ew, iter});
                    ways[iter] = ways[node];
                }
                else if(di+ew == dist[iter]){
                    ways[iter] = (ways[iter]+ ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
}; 
