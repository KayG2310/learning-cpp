// recursive code
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& arr){
        if(day==0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                int pt = arr[day][i] + f(day-1, i, arr);
                maxi = max(maxi, pt);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        return f(n-1, 3, arr);
    }
};

// memoized code, tc = 12n, sc = 5n
class Solution {
  public:
    int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>&dp){
        if(day==0){
            int maxi = 0;
            for(int i=0; i<3; i++){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                int pt = arr[day][i] + f(day-1, i, arr, dp);
                maxi = max(maxi, pt);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n, vector<int>(4, -1));
        return f(n-1, 3, arr, dp);
    }
};


// tab, tc = same sc = 4n
int ninjaTraining(int n, vector<vector<int>>& points) {
  // Create a 2D DP (Dynamic Programming) table to store the maximum points
  // dp[i][j] represents the maximum points at day i, considering the last activity as j
  vector<vector<int>> dp(n, vector<int>(4, 0));

  // Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (recursively calculated)
          int activity = points[day][task] + dp[day - 1][task];
          // Update the maximum points for the current day and last activity
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
}



// sc opt 4 elements prev store
// tc same sc = o(4)
int ninjaTraining(int n, vector<vector<int>>& points) {
  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    // Create a temporary vector to store the maximum points for the current day's activities
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (stored in prev)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    // Update prev with the maximum points for the current day
    prev = temp;
  }

  // The maximum points for the last day with any activity can be found in prev[3]
  return prev[3];
}

