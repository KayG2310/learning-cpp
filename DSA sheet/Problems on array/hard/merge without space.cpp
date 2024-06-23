// my solution ---> O(n*m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i=0; i<n;i++){
            // we need to go only till the first m elements since insertion is in num1
            while(j<nums1.size()-n && nums1[j]<nums2[i]){
                j++;
                // j ends up at an index that after which you can insert nums2
            }
            nums1.insert(nums1.begin()+j, nums2[i]);
        }

        // now we need to remove trailing zeroes
        auto it = nums1.end();
        it--;
        // we are now at end
        for(int i=0; i<n;i++){
            nums1.erase(it);
            it--;
        }    
    }
};
