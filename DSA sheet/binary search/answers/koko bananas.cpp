// brute force not all test cases passed
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we can increment one by one but that's gonna take long
        int n =1;
        while(true){
            int sum = 0;
            for(int i=0; i<piles.size(); i++){
                sum+= ceil((double)piles[i]/n);
                if(sum>h) break;
            }
            if(sum<=h) return n;
            n+=1;
        }
        return n;
    }

// dry run 
/*
3,6,7,11 n=1 -> sum = 3, if no
sum = 9, if yes break, if no, n=2
sum=0, sum = 2, if no, sum = 5, if no, sum = 10 break, n=3
sum = 0, sum=1, if no, sum=3, if no, sum = 6, if no, sum=10 break
n=4 
*/
    
};

// optimal 
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // we can increment one by one but that's gonna take long
        int ans = INT_MAX;
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid=0;
        while(low<=high){
            mid = (low+high)/2;
            long long sum=0;
            for(int i=0; i<piles.size(); i++){
                sum+=ceil((double)piles[i]/mid);
            }
            if(sum>h){
                low = mid+1;
            }
            else if(sum<=h){
                ans = min(ans, mid);
                high = mid-1;
            }

        }
        return ans; 

    } 
};
