class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> ans(queries);
        for(int i=0; i<queries; i++){
            int cnt = 0;
            for(int j=indices[i]; j<arr.size(); j++){
                if(arr[j]>arr[indices[i]]) cnt++;
            }
            ans[i] = cnt;
        }
       return ans;
    }

};
