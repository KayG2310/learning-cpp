// same as aggressive cows, book allocation or other logic of this sort 
class Solution {
private:
bool canweplace(vector<int>&nums, int subs,int maxsum){
    int cur_sub = 1, last=nums[0];
    for(int i=1; i<nums.size(); i++){
        if(last+nums[i]>maxsum){
            cur_sub++;
            last = nums[i];
        }
        else{
            last +=nums[i];
        }
        if(cur_sub>subs) return false;
    }
    return true;
}
public:
    int splitArray(vector<int>& nums, int subs) {
        int n = nums.size();
        if(n<subs) return -1;
        if(n==subs) return *max_element(nums.begin(), nums.end());
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0), mid = 0;
        int ans = INT_MAX;
        while(low<=high){
            mid = (low+high)/2;
            if(canweplace(nums, subs,mid)==true){
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

