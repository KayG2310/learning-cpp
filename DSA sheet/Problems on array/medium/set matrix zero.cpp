// brute force submitted on leetcode
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); //columns
        vector<int> row(n,0); // int row[n] = {0};
        vector<int> col(m,0);

        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(matrix[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // we traverse again
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }    

    }
};


// optimal 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); //columns
        int col0 = 1;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    if(j!=0){
                        matrix[0][j] = 0;
                        // only if it is not the first column
                    }
                    else {
                        col0 = 0;
                    }
                    
                }
            }
            
        }
        // we traverse again on 1st row and 1st column
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] != 0){
                   if(matrix[0][j] == 0 || matrix[i][0] == 0){
                       matrix[i][j] = 0;
                   }
                }
            }
        }
        
        if(matrix[0][0]==0){
            for(int j=0; j<m; j++) matrix[0][j] = 0;
        }
        if(col0==0){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }

    }
};
