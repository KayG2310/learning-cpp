class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i=0; i<rows; i++){
            int low = 0, high = columns -1, mid=0;
            while(low<=high){
                mid = (low+high)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]<target) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};

// tc = O(n*logm) 

// optimized version of above code 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i=0; i<rows; i++){
            if(matrix[i][0]<=target && matrix[i][columns-1]>=target){
                int low = 0, high = columns -1, mid=0;
                while(low<=high){
                    mid = (low+high)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) low = mid+1;
                    else high = mid-1;
                }
            }
        }
        return false;
    }
};

// most optimal code 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int row=0, col = columns-1;
        while(row<rows && col>=0){
            // because you increase the rows and decrease the columns
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target){
                // means that row is not the one
                row++;
            }
            else col--;
        }
        return false;
    }
};
