class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        int n = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<k; i++){
            n += arr[i].size();
            for(int j=0; j< arr[i].size(); j++){
                pq.push(arr[i][j]);
            }
            
        }
        vector<int>ans;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
}; 

// tc = k^2 * log k, sc = k
