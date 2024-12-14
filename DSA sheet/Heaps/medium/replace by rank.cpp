class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<n; i++){
            pq.push({arr[i], i});
        }
        vector<int>ans(n);
        int cnt = 1;
        int index = -1;
        int num = -1;
        while(!pq.empty()){
            index = pq.top().second;
            num = pq.top().first;
            ans[index] = cnt;
            
            pq.pop();
            if(pq.top().first == num) cnt--;
            cnt++;
        }
        return ans;
        
    }

}; 

// tc = nlogn + n
