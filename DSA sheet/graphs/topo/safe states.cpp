class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // adjcacency list already given
        int n = graph.size();
        vector<vector<int>>rev(n);
        vector<int>indegree(n);
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: rev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;

    }
};
