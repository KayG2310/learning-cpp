class Solution 
{
    private:
        // Comparison function to sort jobs by profit in descending order
        static bool comp(Job a, Job b) {
            return a.profit > b.profit;
        }
    public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxdays = 0;
        // Find the maximum deadline
        for(int i = 0; i < n; i++) {
            maxdays = max(maxdays, arr[i].dead);
        }

        // Array to keep track of which days are occupied (-1 means the day is free)
        vector<int> days(maxdays + 1, -1);
        vector<int> ans(2); // [number of jobs, total profit]
        
        // Sort jobs in descending order of profit
        sort(arr, arr + n, comp);
        
        int cnt = 0, profit = 0;
        
        // Iterate over each job
        for(int i = 0; i < n; i++) {
            // Find a free slot for this job (latest possible before its deadline)
            for(int j = arr[i].dead; j > 0; j--) {
                if(days[j] == -1) { // If the day is free
                    days[j] = arr[i].id; // Assign the job to this day
                    cnt += 1;
                    profit += arr[i].profit;
                    break; // Job assigned, move to the next job
                }
            }
        }
        
        ans[0] = cnt; // Number of jobs completed
        ans[1] = profit; // Total profit earned
        return ans;
    } 
};
