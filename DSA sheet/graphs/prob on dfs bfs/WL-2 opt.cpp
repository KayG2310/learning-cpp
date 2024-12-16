class Solution {
public:
    void dfs(string word, vector<string>& seq, vector<vector<string>>&ans, string &start, unordered_map<string, int>&mpp){
        if(word==start){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i=0; i<word.length(); i++){
            char original = word[i];
            for(char ch = 'a'; ch<='z'; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word, seq, ans, start, mpp);
                    seq.pop_back();
                }
            }
            word[i] = original;

    }
    }
    vector<vector<string>> findLadders(string start, string end, vector<string>& word) {
        queue<string>q;
        q.push(start);
        vector<vector<string>>ans;
        unordered_map<string, int> mpp;
        mpp[start] = 1;
        int n = start.size();
        unordered_set<string>s(word.begin(), word.end());
        s.erase(start);
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == end) break;
            for(int i=0; i < n; i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        q.push(word);
                        s.erase(word);
                        mpp[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(end) != mpp.end()){
            vector<string>seq;
            seq.push_back(end);
            dfs(end, seq, ans, start, mpp);
        }
        return ans;
    }
};
