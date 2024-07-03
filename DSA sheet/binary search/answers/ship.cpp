// submitted on leetcode 
class Solution {
private:
    bool checker(vector<int>& weights, int days, int capacity){
        int our = 0;
        int day = 1;
        for(int i=0; i<weights.size(); i++){
            if(weights[i]+our>capacity){
                day+=1;
                our = weights[i];
            }
            else{
                our+=weights[i];
            }
        }
        if(day<=days) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int mid = 0;
        int ans = INT_MAX;
        while(low<=high){
            mid = low+(high-low)/2;
            if(checker(weights, days, mid)==true){
                ans = min(ans, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
