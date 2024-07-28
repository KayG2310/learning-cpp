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

// better / optimal O(n1+2n2) using stacks sc = n1+2n2 (map+stack)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        stack<int>st;
        unordered_map<int,int>holder;
        
        for(int i=nums2.size()-1; i>=0; i--){
            while(! st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                holder[nums2[i]] = -1;
            }
            else{
                holder[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
    }
    for(int i = 0; i<nums1.size(); i++){
        ans[i] = holder[nums1[i]];
    }
    return ans;

        
    }
};
