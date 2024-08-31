// tc = n, sc = 1
class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long sum1 = 0, sum2 = 0;
        sort(bt.begin(), bt.end());
        for(int i=1; i<bt.size(); i++){
            sum2 += bt[i-1];
            sum1+=sum2;
            /*
            1 2 3 4 7
            i = 1, sum
            */
        }
        return sum1/bt.size();
    }
};
