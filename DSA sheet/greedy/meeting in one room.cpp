class Solution {
  private:
    struct meeting{
       int start;
       int end;
       //int pos;
    };
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comparator(struct meeting m1, meeting m2) {
         return m1.end<m2.end;
      }
    int maxMeetings(int n, int start[], int end[]) {
        meeting arr[n];
        for (int i = 0; i < n; i++) {
            arr[i].start = start[i], arr[i].end = end[i]; 
            //meet[i].pos = i + 1;
        }
        sort(arr, arr+n, comparator);
        int cnt = 1, last = arr[0].end; 
        for(int i=1; i<n; i++){
            if(arr[i].start>last){ 
                cnt++;
                last = arr[i].end;
            }
        }
        return cnt;
    }
};

// greed is more number of meetings not longer ones
