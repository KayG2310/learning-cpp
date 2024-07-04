//submitted on leetcode
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }
        // merged is created
        int x = merged.size();
        cout<<x;
        if(x%2==0){
            int y = x/2; // y=2, z=1 
            int z = y-1;
            cout<<merged[y]<<" "<<merged[z];
            return (double)((merged[y]+merged[z])/2.0);
        }
        return (double)(merged[x/2]);
    }
};

// binary search
// optimizing space complexity
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size()+nums2.size();
        int y = x/2, numy = 0;
        int z = y-1, numz=0;
        int i=0, j=0;
        int m=0;
        int flag = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                
                if(m==y) {
                    numy=nums1[i];
                    flag+=1;
                }
                if(m==z){
                    numz = nums1[i];
                    flag+=1;
                } 
                i++;
                m++;
                if(flag==2) break;
            }
            else{
                
                if(m==y) {
                    numy=nums2[j];
                    flag+=1;
                }
                if(m==z){
                    numz = nums2[j];
                    flag+=1;
                } 
                j++;
                m++;
                if(flag==2) break;
            }
        }
        while(i<nums1.size()){
            if(m==y) {
                numy=nums1[i];
                flag+=1;
            }
            if(m==z){
                numz = nums1[i];
                flag+=1;
            } 
            i++;
            m++;
            if(flag==2) break;
        }
        while(j<nums2.size()){
            if(m==y) {
                numy=nums2[j];
                flag+=1;
            }
            if(m==z){
                numz = nums2[j];
                flag+=1;
            } 
            j++;
            m++;
            if(flag==2) break;
        }
        cout<<x<<" "<<numy<<" "<<numz;
        if(x%2==0){
            return (double)((numy+numz)/2.0);
        }
        return (double)(numy);
    }
};

/*
1 2 & 3 4
x=4, y = 2, numy=0.   z = 1, numz=0, m=0, flag=0
1<3, if no, if no, i = 1, m=1, flag =0
2<3, if no, if yes, i=2,  m=2, flag = 1

*/


// optimal code
