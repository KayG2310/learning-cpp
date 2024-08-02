// brute force
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans = -1;
        for(int i=0; i<mat.size(); i++){
            int dup = -1;
            bool flag = true;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] != 0) flag = false;
            }
            if(flag==true){
                bool flag2 = true;
                dup = i;
                for(int k=0; k<mat.size(); k++){
                    if(dup==k) continue;
                    if(mat[k][dup]!=1){
                        flag2 = false; break;
                    }
                }
                if(flag2) {ans = dup;return ans;}
            }
        }
        return ans;
        
    }
};

// better approach ->
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int top = 0;
        int bottom = mat.size()-1;
        while(top<bottom){
            if(mat[top][bottom] !=0){
                // top knows bottom, top can't be celebrity
                top++;
            }
            else if(mat[bottom][top] != 0){
                bottom--;
            }
            else{
                top++;
                bottom--;
            }
        }
        if(top>bottom) return -1;
        for(int i=0; i<mat.size(); i++){
            if(i==top) continue;
            if(mat[top][i]==0 && mat[i][top]==1) continue;
            else return -1;
        }
        return top;
    }
};

// using stacks (same logic) keep popping and appending two
