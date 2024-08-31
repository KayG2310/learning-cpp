class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        sort(in.begin(), in.end(), [](vector<int>&in1, vector<int>&in2)->bool{
            if(in1[0]==in2[0]){
                return in1[1]<in2[1];
            }
            return in1[0]<in2[0];
        });
        ans.push_back(in[0]);
        for(int i = 1; i<in.size(); i++){
            int k=ans.size()-1;
            if(in[i][0]==ans[k][1]){
                // meaning current start is equal to last end
                ans[k][1] = max(ans[k][1], in[i][1]);
            }
            else if(in[i][0]<ans[k][1]){
                ans[k][1] = max(ans[k][1], in[i][1]);
                ans[k][0] = min(ans[k][0], in[i][0]);
            }
            else{
                ans.push_back(in[i]);
            }

        }
        return ans;
    }
};

// tc = nlogn (for sorting) + n 
// sc = 1
