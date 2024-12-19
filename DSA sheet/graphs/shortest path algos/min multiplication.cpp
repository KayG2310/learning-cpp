#define pii pair<int, int>
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pii>q;
        q.push({0, start});
        vector<int>d(1e5, 1e9);
        if(end==start) return 0;
        d[start] = 0;
        int mod = 1e5;
        while(!q.empty()){
            int node = q.front().second;
            int step = q.front().first;
            q.pop();
            for(auto it:arr){
                int num = (it*node)%mod;
                if(step+1 < d[num]){
                    d[num] = step+1;
                    if(num==end) return step+1;
                    q.push({step+1, num});
                    
                }
            }
        }
        return -1;
    }
};
