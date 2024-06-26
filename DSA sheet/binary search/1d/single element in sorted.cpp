class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr = 0;
        for(int i=0; i<nums.size(); i++){
            xr = xr ^ nums[i];
        }
        return xr;
    }
};

// another solution using binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        int n= arr.size();
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int low=1, high = n-2, mid=0;
    while(low<=high){
        mid = low + (high-low)/2;
        if(mid%2!=0){
            // mid is an odd index
            if(arr[mid-1]==arr[mid]){
                // even odd, answer to right
                low = mid+1;
            }
            else if(arr[mid+1]==arr[mid]){
                // answer lies to left
                high = mid-1;
            }
            else{
                return arr[mid];
            }
        }
        
        else{ // mid is even
            if(arr[mid-1]==arr[mid]){
                // odd even, answer to left
                high = mid-1;
            }
            else if(arr[mid+1]==arr[mid]){
                // even odd lies to right
                low = mid+1;
            }
            else{
                return arr[mid];
            }

        }
    }
    return mid;
    }
};
