class Solution {
public:
    void dfs(int row, int col, int color, vector<vector<int>>& image, vector<int>& neigh_rows, vector<int>& neigh_col, int ini, vector<vector<int>>&visited){

        image[row][col] = color;
        visited[row][col] = 1;
        // up down left right 
        for(int i=0; i<4; i++){
            int nrow = row+neigh_rows[i];
            int ncol = col+neigh_col[i];
            if(nrow>=0 && ncol>=0 && nrow<image.size() && ncol < image[0].size() && image[nrow][ncol] == ini && visited[nrow][ncol]==0){
                // image[nrow][ncol] = color;
                dfs(nrow, ncol, color, image, neigh_rows, neigh_col, ini, visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inco = image[sr][sc];
        // vector<vector<int>>ans = image;
        // you can create a copy and work on it as data modification is not preferred but we will do in place
        vector<int>neigh_rows = {-1, 1, 0, 0};
        vector<int>neigh_cols = {0, 0, -1, 1};
        vector<vector<int>>visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(sr, sc, color, image, neigh_rows, neigh_cols, inco, visited);
        return image;
    }
};
