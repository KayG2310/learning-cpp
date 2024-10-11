class Solution {
public:
    vector<int>drow = {1, -1, 0,0};
    vector<int>dcol = {0, 0, 1,-1};
    bool f(int x, int y, vector<vector<char>>& board, string &word, int i, vector<vector<int>>&visited, int n, int m){
        if(i==word.length()){
            return true;
        }
        bool a = false;
        for(int k=0; k<4; k++){
            int nrow = x+drow[k];
            int ncol = y+dcol[k];
            if(nrow<m && ncol<n && nrow>=0 && ncol>=0 && board[nrow][ncol] == word[i] && visited[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                a = a||f(nrow, ncol, board, word, i+1, visited, n, m); 
                visited[nrow][ncol]=0;

            }
        }
        return a;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>visited(m, vector<int>(n,0));
                    visited[i][j] = 1;
                    if (f(i, j, board, word, 1, visited, n, m)==true){
                        return true;
                    }

                }
            }
        }
        return false;
    }
};
