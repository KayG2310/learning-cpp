class Solution {
public:
    bool static comparator(vector<int>&interval1, vector<int>&interval2){
        return interval1[1]<interval2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        // sort(intervals.begin(),interval.end(), [](vector<int>&i1,vector<int>&i2)->bool{
        //     return i1[1]<i2[1];
        // });
        int cnt = 1;
        int last = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=last){
                cnt++;
                last = intervals[i][1];
            }
        }
        return intervals.size()-cnt;
        
    }
};

// tc = nlogn + n
