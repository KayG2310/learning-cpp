// brute force - will exceed tle
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        vector<int>ms;
        for(int i=0;i<R; i++){
            for(int j=0; j<C; j++){
                ms.push_back(matrix[i][j]);
            }
        }
        sort(ms.begin(), ms.end());
        int len = ms.size();
        int y=len/2;
            int z = y-1;
        if(len%2==0){
            
            return (ms[y]+ms[z])/2;
        }
        return ms[y];
    }
};

// optimal using binary search

class Solution{ 
private:
    int countsmall(vector<vector<int>> &matrix, int n, int m, int x){
        int cnt = 0;
        for(int i=0; i<n;i++){
            cnt+= (upper_bound(matrix[i].begin(), matrix[i].end(),x)-matrix[i].begin());
        }
        return cnt;
    }
public:
    int median(vector<vector<int>> &matrix, int n, int m){
        int low = INT_MAX, high = INT_MIN;
        for(int i=0; i<n; i++){
            low = min(low, matrix[i][0]); // lowest element
            high = max(high, matrix[i][m-1]); // highest element
        }
        int req = (m*n)/2; 
        while(low<=high){
            int mid = (low+high)/2; //middle number
            int smallequal = countsmall(matrix, n,m,mid); // calculate smaller than middle number, if its less we can go to to the right
            // otherwise we go to the left oooooohhhhhhh
            if(smallequal<=req) low = mid+1;
            else high = mid-1;
        }
        return low;
        
    }
};
