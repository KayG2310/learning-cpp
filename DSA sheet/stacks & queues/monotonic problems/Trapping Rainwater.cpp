// brute force approach - tle
class Solution {
public:
    int trap(vector<int>& height) {
        // brute force 
        int sum = 0;
        for(int i=0; i<height.size(); i++){
            int maxleft = 0;
            int maxright = 0;
            for(int left = 0; left<=i; left++){
                maxleft = max(maxleft, height[left]);
            }
            for(int right = i; right<height.size(); right++){
                maxright = max(maxright, height[right]);
            }
            sum += min(maxleft, maxright) - height[i];
        }
        return sum;
    }
};
/*
dry run ->
0 : ml = 0, mr = 3 sum = 0
1 : ml = 0, mr = 3 sum = -1
*/

// better tc = 2n, sc = 2n
class Solution {
public:
    int trap(vector<int>& height) {
        // better approach
        int maxleft = height[0], maxright = height[height.size()-1];
        vector<int>prefix(height.size());
        vector<int>suffix(height.size());
        for(int i=0; i<height.size(); i++){
            maxleft = max(height[i], maxleft);
            prefix[i] = maxleft;
        }
        for(int i=height.size()-1; i>=0; i--){
            maxright = max(height[i], maxright);
            suffix[i] = maxright;
        }
        int cnt = 0;
        for(int i=0; i<height.size(); i++){
            cnt += min(prefix[i], suffix[i]) - height[i];
        }
        return cnt;
    }
};

// optimal tc = n, sc = 1
class Solution {
public:
    int trap(vector<int>& height) {
        // optimal two pointer approach
        int maxleft = 0, maxright = 0, left = 0, right = height.size()-1, cnt=0;
        while(left <=right){
            if(height[left] <= height[right]){
                if(height[left]>=maxleft) maxleft = height[left];
                else cnt += maxleft - height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright = height[right];
                else cnt += maxright - height[right];
                right--;
            }
        }
        return cnt;
    }
};

