// brute force 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int size2 = nums.size(); //4

        k = k%size2; // k = 2
        if(size2==1 || k==0) return;
        int temp[k];
        for(int i=size2-k; i<size2;i++){
            temp[i+k-size2] = nums[i];
        }
        // 2<=i<4, i = 2,3
        // i = 2, temp[2+2-4=0] = nums[2] => temp = {3}
        // i = 3, temp[3+2-4=1] = nums[3] => temp = {3,99}
        // now our task is to input -1,-100 correctly
        
        for (int i = size2 - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
    }
};





// optimal approach
