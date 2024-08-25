// q link https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// my soln - some logical errors
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int p = 0, c=0, i=0, j= cp.size()-1;
        while(c!=k){
            if(cp[i]>cp[j]){
                p+=cp[i];
                i++;
            }
            else if(cp[j]>cp[i]){
                p+=cp[j];
                j--;
            }
            else{
                p+=cp[i];
                if(i+1<cp.size() && j-1>-1 && cp[i+1]>=cp[j-1]) i++;
                else j--;
            }
            c++;
        }
        return p;
    }
};


// striver solution , tc = 2k, sc = 1
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        // int sum = 0, lels = k;
        int lsum = 0, rsum = 0, sum = 0;
        for(int i=0; i<k; i++){
            lsum = lsum + cp[i];
        }
        sum = lsum;
        int r=cp.size()-1;
        for(int i=k-1; i>=0;i--){
            lsum = lsum - cp[i];
            rsum += cp[r];
            r-=1;
            sum = max(sum, lsum+rsum);
        }
        return sum;
    }
};
