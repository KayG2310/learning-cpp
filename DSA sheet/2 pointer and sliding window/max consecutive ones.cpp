// better approach, tc = 2n, sc = 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int maxlen = 0, l=0, r=0;
        while(r<nums.size()){
            cout<<l<<" "<<r<<endl;
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0){ zeros--;}
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

// optimal approach
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int maxlen = 0, l=0, r=0;
        while(r<nums.size()){
            //cout<<l<<" "<<r<<endl;
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
