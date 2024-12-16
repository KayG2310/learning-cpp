class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& word) {
        vector<vector<string>> ans;
        if(start==end) return {{}};
        queue<vector<string>>q;
        unordered_set<string>s(word.begin(), word.end());
        vector<string>st = {start};
        s.erase(start);
        q.push(st);
        while(!q.empty()){
            vector<string>temp = q.front();
            string fs = temp.back();
            if(s.find(fs) != s.end()) s.erase(fs);
            q.pop();
            int n = fs.length();
            if(fs == end) {
                if(ans.size() ==0) ans.push_back(temp);
                else{
                    if(temp.size()==ans.back().size()) ans.push_back(temp);
                }
            }
            for(int i=0; i<n; i++){
                for(char ch = 'a'; ch<='z'; ch++){
                    string news = fs;
                    vector<string>temp2 = temp;
                    news[i] = ch;
                    if(s.find(news) != s.end()){
                        temp2.push_back(news);
                        q.push(temp2);
                    }
                }
            }

        }
        return ans;
    }
};
