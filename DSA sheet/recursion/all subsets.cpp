class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>m;
        for(int i=0; i<(1<<n); i++){
            vector<int>sub;
            int j=i, c=0;
            while(j){
                if((j&1) != 0){
                    sub.push_back(nums[n-1-c]);
                }
                j=j>>1;
                c++;
            }
            m.push_back(sub);
        }
        return m;
    }
};
