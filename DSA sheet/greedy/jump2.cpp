class Solution {
private:
    int f(int ind, int jump, int n,vector<int>& nums){
        if(ind>=n-1){ 
            return jump;
        }
        int mini = INT_MAX;
        for(int i=0; i<nums[ind]; i++){
            mini = min(mini, f(ind+i+1, jump+1, n , nums));
        }
        return mini;
    }
public:
    int jump(vector<int>& nums) {
        // recursive exponential code
        return f(0,0,nums.size(), nums);
    }
};

// n^n, recursive stack space = n

class Solution {
public:
    int jump(vector<int>& nums) {
        // recursive exponential code
        // return f(0,0,nums.size(), nums);
        int l=0, r=0, jumps = 0;
        while(r<nums.size()-1){
            int farthest = 0;
            for(int i = l; i<=r; i++){
                farthest = max(i+nums[i], farthest);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};

// n, 1
