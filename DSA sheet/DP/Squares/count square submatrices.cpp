class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>copy(n, vector<int>(m, 0));
        int sum = 0;
        for(int i=0; i<m; i++){
            copy[0][i] = matrix[0][i];
            sum += copy[0][i];
        }
        for(int i=0; i<n; i++){
            copy[i][0] = matrix[i][0];
            sum += copy[i][0];
        }
        sum -= matrix[0][0];
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==0) copy[i][j] = 0;
                else{
                    copy[i][j] = min(copy[i-1][j-1], min(copy[i-1][j], copy[i][j-1]))+1;
                }
                sum += copy[i][j];
            }
        }
        return sum;
    }
};
