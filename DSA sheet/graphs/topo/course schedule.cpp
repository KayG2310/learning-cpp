class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<int>indegree(num);
        for(int i=0; i<num; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<num; i++){
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
        return topo.size()==num;
    }
};
