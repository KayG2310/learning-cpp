// brute force approach is sort the array and the last index element is the answer
// optimal approach - keep updating the maximum element variable
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max = arr[0];
        for(int i=1; i<n;i++){
            if(arr[i]> max){
                max = arr[i];
            }
        }
        return max;
    }
};
