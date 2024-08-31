// wrong logic 
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         if(ratings.size()==1) return 1;
//         int n = ratings.size();
//         int cnt = ratings.size();
//         if(ratings[0]>ratings[1]) cnt++;
//         if(ratings[n-1]>ratings[n-2]) cnt++;

//         for(int i=1; i<=n-2; i++){
//             if(ratings[i]>ratings[i-1] || ratings[i]>ratings[i+1]) cnt++;
//         }
//         return cnt;
//     }
// };


// 3n solution, sc = 2n
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1) return 1;
        int n = ratings.size();
        int sum = 0;
        vector<int>left(n,1), right(n,1);

        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]) left[i]+= (left[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]) right[i]+= (right[i+1]);
        }
        for(int i=0; i<n; i++){
            sum +=max(left[i], right[i]);
            cout<<sum<<" ";
        }
        return sum;
    }
};


// tc = n, sc = 1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i= 1;
        int n = ratings.size();
        if(n==1) return 1;
        while(i<n){
            // plateau condition
            if(ratings[i] == ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                // upward curve
                peak++;
                sum +=peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i-1]>ratings[i]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak) sum+= (down-peak);
        }
        return sum;
    }
};
