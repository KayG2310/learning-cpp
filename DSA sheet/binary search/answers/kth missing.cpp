// brute force leetcode 1st submission that was accepted
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        int j=0;
        while(j<arr.size()){
            if(arr[j]==i){
                // means i is not missing, do nothing with k
                j++;
                i++;
            }
            else{
                // i is missing, 
                k-=1;
                if(k==0){
                    return i;
                }
                i++;
            }
        }
        if(k>0){
            i=i+k-1;
            return i;
        }
        return i;
    }
};
// tc = O(n)

// optimal submission 2 on leetcode
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0, high = arr.size()-1, mid=0, missing=0;
        // more = k-missing
        while(low<=high){
            mid = (low+high)/2;
            missing = arr[mid]-(mid+1);
            if(missing<k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return k+low;

    }
};
