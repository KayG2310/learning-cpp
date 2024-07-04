class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        int ms=0, i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ms++;
                if(ms==k) return nums1[i];
                i++;
            }
            else{
                ms++;
                if(ms==k) return nums2[j];
                j++;
            }
        }
        while(i<n){
            ms++;
            if(ms==k) return nums1[i];
            i++;
        }
        while(j<m){
            ms++;
            if(ms==k) return nums2[j];
            j++;
        }
    }
};
