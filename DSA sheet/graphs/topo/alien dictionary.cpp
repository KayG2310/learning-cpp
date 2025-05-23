class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        // code 
        int n = dict.size();
        vector<vector<int>>adj(k);
        for(int i=0; i<n-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.length(), s2.length());
            for(int ptr = 0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int>indegree(k);
        for(int i=0; i<k; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<k; i++){
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
        string ans = "";
        if(topo.size()==k){
            for(auto it: topo){
                ans += char(it+'a');
            }
        }
        return ans;
    
    }
};
