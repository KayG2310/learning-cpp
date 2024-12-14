// 64 out of 72 passed
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int globaltime = 0;
        int cnt = 0;
        priority_queue<pair<int, char>>pq;
        set<int>s;
        map<char, int>m;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
        }
        for(auto &it : m){
            pq.push({it.second, it.first});
        }
        // now priority wise he have arranged
        int ans = 0;
        while(!pq.empty()){
            globaltime = cnt; 
            ans = max(ans, globaltime);
            s.insert(globaltime);
            int occ = pq.top().first;
            occ--;
            while(occ--){
                globaltime += n+1;
                ans = max(ans, globaltime);
                s.insert(globaltime);
                // cout<<globaltime<<endl;
            }
            cnt++;
            while(s.find(cnt) != s.end()) cnt++;
            // s.insert(cnt);
            pq.pop();
        }
        return ans+1;
    }
}; 

// another solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char c : tasks) 
            counts[c]++;  // Count the frequency of each task
        
        priority_queue<int> pq;
        for (auto c : counts) 
            pq.push(c.second);  // Push all task frequencies into the max-heap
        
        int result = 0;

        // Process tasks in cycles
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;  // To temporarily store decremented frequencies

            // Process up to (n + 1) tasks
            for (int i = 0; i < n + 1; ++i) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top() - 1);  // Decrement task frequency
                    pq.pop();
                    time++;  // Count the current time slot
                }
            }

            // Re-insert tasks with remaining frequencies into the heap
            for (auto t : tmp) {
                if (t > 0) pq.push(t);
            }

            // Update total time
            result += pq.empty() ? time : (n + 1);  // Handle idle time
        }

        return result;
    }
};
