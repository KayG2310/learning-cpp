// recursive, tc = exponential, sc = n
class Solution {
public:
    int f(int i, int id, vector<int>& prices, int n, int k, int &profit){
        // base case
        if(i==n) return 0;
        if(id == 2*k) return 0;

        if(id%2==0) {
            // buying possible
            profit = max(f(i+1, id+1, prices, n, k, profit)-prices[i], f(i+1, id, prices, n, k, profit));
        }
        else {
            // selling possible
            profit = max(f(i+1, id+1, prices, n, k, profit)+prices[i], f(i+1, id, prices, n, k, profit));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // if k transactions possible, transaction number from 0 to 2k-1
        int profit = 0;
        int n = prices.size();
        return f(0, 0, prices, n, k, profit);
    }
};

// memoized 
