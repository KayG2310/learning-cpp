class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        int sum = 0;
        vector<int>visited(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if(visited[node]==1) continue;
            sum += wt;
            visited[node] = 1;
            for(auto &val: adj[node]){
                if(visited[val[0]]==0){
                    pq.push({val[1], val[0]});
                }
            }
        }
        return sum;
    }
};
