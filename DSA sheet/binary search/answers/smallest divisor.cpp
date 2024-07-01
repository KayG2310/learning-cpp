class Solution {
private:
    bool sumd(vector<int>& nums, int threshold, int divisor){
        long long s = 0;
        for(int i=0; i<nums.size(); i++){
            s+=ceil((double)nums[i]/divisor);
            if(s>threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = INT_MAX;
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid=0;
        while(low<=high){
            mid = (low+high)/2;
            if(sumd(nums,threshold,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
    }
};
