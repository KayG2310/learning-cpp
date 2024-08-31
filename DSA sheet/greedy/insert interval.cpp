class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        if(in.size()==0) return in;
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
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};

// another 
class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        if(in.size()==0) return in;
        vector<vector<int>> ans;
        // sort(in.begin(), in.end(), [](vector<int>&in1, vector<int>&in2)->bool{
        //     if(in1[0]==in2[0]){
        //         return in1[1]<in2[1];
        //     }
        //     return in1[0]<in2[0];
        // });
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
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = 0, high = intervals.size()-1, mid = 0;
        while(low<=high){
            mid = (low+high)/2;
            if(intervals[mid][0]>newInterval[0]) high = mid-1;
            else{
                low = mid+1;
            }
        }
        intervals.insert(intervals.begin()+low, newInterval);
        return merge(intervals);
    }
};
