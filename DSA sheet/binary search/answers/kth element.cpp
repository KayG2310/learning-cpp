// tc = O(k) loop will run till whenever k is found
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

//log(min(n1,n2))
double median(vector<int> &a, vector<int>&b,n1,n2,k){
    
    if(n1>n2) return median(b,a,n2,n1,k);
    int low = max(0,k-n2), high = min(n1,k);
    int left = k;
    int n = n1+n2;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1<n1) r1 = a[mid1];
        if(mid2<n2) r2 = b[mid2];
        if(mid1-1>=0) l1 = a[mid1-1];
        if(mid2-1>=0) l2 = a[mid2-1];
        if(l1<=r2 && l2<=r1){
                return max(l1,l2);
        }
        else if(l1>r2){
            high = mid1-1;
        }
        else low = mid1+1;
    }
    return 0;
}
