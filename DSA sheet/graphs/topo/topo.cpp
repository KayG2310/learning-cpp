class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int>&visited, vector<int>&ans){
        visited[node] = 1;
        for(auto &val: adj[node]){
            // if(adj[node].size()==0){
            //     // push to stack
            //     ans.push_back(node);
            // }
            if(visited[val]==0){
                // hasn't been visited yet
                dfs(val, adj, visited, ans);
            }
            // else if(val.size() == empty)
        }
        ans.push_back(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>visited(V,0);
	    vector<int>ans;
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            dfs(i, adj, visited, ans);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	    
	}
};
