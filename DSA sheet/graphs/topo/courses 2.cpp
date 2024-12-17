class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n = num;
        vector<int>indegree(n);
        vector<vector<int>>adj(num);
        vector<int>visited(num);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i] ==0) q.push(i);
            
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==num) return topo;
        return {};
    }
};
