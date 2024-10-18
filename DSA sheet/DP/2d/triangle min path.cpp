// simple recursive code 2^m
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int m){
        if(i == m-1) return triangle[i][j];
        int d = triangle[i][j]+f(i+1, j, triangle, m);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, m);
        return min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        return f(0,0, triangle, m);
    }
};

// memoization, tc = n2, sc = n2+n
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int m, vector<vector<int>>&dp){
        if(i == m-1) return triangle[i][j];
        if(dp[i][j]!= -1) return dp[i][j];
        int d = triangle[i][j]+f(i+1, j, triangle, m, dp);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, m, dp);
        return dp[i][j] = min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m, vector<int>(m, -1));
        return f(0,0, triangle, m, dp);
    }
};

// tabular approach --> recursive stack space removed
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    // Create a 2D DP (dynamic programming) array to store minimum path sums
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

// space opt 
int minimumPathSum(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}
