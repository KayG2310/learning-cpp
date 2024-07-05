class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int low = 0, high = rows*columns -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            cout<<low<<" "<<high<<" "<<mid<<endl;
            // converting mid to rows and columns
            // for eg - low = 0, high = 11, mid = 5 refers to 6th element, 
            if(matrix[mid/columns][mid%columns]==target){
                return true;
            }
            else if(matrix[mid/columns][mid%columns]>target){
                //yup
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};
// rows = 1, columns = 2, low =0, high = 1
// mid = 0, matrix[0/2][0%1] = 1<target low = 1,high=1, mid = 1
// 1/2 = 0, 1%2 = 1, matrix[0][1]==3

