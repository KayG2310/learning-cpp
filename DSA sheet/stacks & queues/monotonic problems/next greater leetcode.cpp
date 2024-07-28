// brute force, tc = O( n1* n2), sc = O(n1) to return the answer no extra space
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ans[i] = -1;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    for(int k=j; k<nums2.size(); k++){
                        if(nums2[k] > nums1[i]){
                            ans[i] = nums2[k];
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// better / optimal O(n1+n2) using stacks
