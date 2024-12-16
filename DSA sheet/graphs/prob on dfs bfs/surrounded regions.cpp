class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&visited, vector<int>&r,vector<int>&c){
        visited[i][j] = 1;
        for(int in=0; in<4; in++){
            int nr = i+r[in];
            int nc = j+c[in];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc] == 'O' && visited[nr][nc] ==0){
                dfs(nr, nc, board, visited, r, c);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<int>r = {-1, 1, 0, 0};
        vector<int>c = {0, 0, -1, 1};
        for(int j=0; j<m; j++){
            if(board[0][j]=='O') dfs(0, j, board, visited, r, c);
            if(board[n-1][j]=='O') dfs(n-1, j, board, visited, r, c);
        }
        for(int i=0; i<n; i++){
            if(board[i][0]=='O') dfs(i, 0, board, visited, r, c);
            if(board[i][m-1]=='O') dfs(i, m-1, board, visited, r, c);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        


    }
};
