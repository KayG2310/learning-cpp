class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0;
        for(int i=0; i<nums.size(); i++){
            //if(maxind>=nums.size()-1) return true;
            if(i>maxind) return false;
            maxind = max(maxind, i+nums[i]);
        }
        return true;
    }
};
// n, sc = 1
