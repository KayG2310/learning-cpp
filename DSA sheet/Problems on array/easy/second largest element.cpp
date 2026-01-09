// second largest element 
// brute force - n-2 if n-2 is not equal to n-1
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
