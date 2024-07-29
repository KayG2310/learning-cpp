class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // brute force
        int area = 0;
        for(int i=0; i<heights.size(); i++){
            int cnt = 1;
            for(int k = i-1; k>=0; k--){
                if(heights[k]>=heights[i]) cnt++;
                else break;
            }
            for(int k= i+1; k<heights.size(); k++){
                if(heights[k]>=heights[i]) cnt++;
                else break;
            }
            area = max(area, cnt*heights[i]);
        }
        return area;
    }
};

// brute force n2, sc = 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // brute force
        int n = heights.size();
        stack<int>st;
        int leftsmall[n], rightsmall[n];
        int area = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) leftsmall[i] = 0;
            else leftsmall[i] = st.top()+1;
            st.push(i);
        }

        // clear stack to be reused
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()) rightsmall[i] = n-1;
            else rightsmall[i] = st.top()-1;
            st.push(i);
        }
        for(int i=0; i<n; i++){
            area = max(area, heights[i]*(rightsmall[i]-leftsmall[i]+1));
            
        }
        return area;
    }
};
