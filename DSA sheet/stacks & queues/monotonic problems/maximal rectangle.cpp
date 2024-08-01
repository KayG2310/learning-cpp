class Solution {
private:
    int hist(vector<int>& heights) {
        // brute force
        int n = heights.size();
        stack<int>st;
        int area = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                area = max(area, height*width);
            }
            
            st.push(i);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>psum(matrix.size(), vector<int>(matrix[0].size(),0));
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = 0; j<=m-1; j++){
            int sum = 0;
            for(int i = 0; i<=n-1; i++){
                sum+= (matrix[i][j] - '0');
                if(matrix[i][j]=='0') sum = 0;
                psum[i][j] = sum;
            }
        }
        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area, hist(psum[i]));
        }
        return area;
    }
};
