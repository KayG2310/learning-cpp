class Solution {
public:
    int ladderLength(string start, string end, vector<string>& word) {
        int ans = 0;
        if(start==end) return 0;
        queue<pair<string, int>>q;
        q.push({start, 1});
        unordered_set<string>s(word.begin(), word.end());
        s.erase(start);
        while(!q.empty()){
            string fs = q.front().first;
            int step = q.front().second;
            q.pop();
            int n = fs.length();
            if(fs == end) return step;
            for(int i=0; i<n; i++){
                for(char ch = 'a'; ch<='z'; ch++){
                    string news = fs;
                    news[i] = ch;
                    if(s.find(news) != s.end()){
                        q.push({news, step+1});
                        s.erase(news);
                    }
                }
            }

        }
        return 0;
    }
}; 
// tc = 
