class Node{
    public:
    Node* links[2];
    bool contains(int bit){
        return links[bit] != NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
public:
    void insert(int num){
        Node* node = root;
        // 0 based indexing
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->contains(bit) == false){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node* node = root;
        int maxnum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->contains(1-bit)){
                maxnum = maxnum | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // sort acc to Ai
        Trie trie;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<vector<int>>oq;
        for(int i=0; i<q; i++){
            oq.push_back({queries[i][1], queries[i][0], i});
        }
        sort(oq.begin(), oq.end());
        vector<int>ans(q, 0);
        int ind = 0;
        for(int i=0; i<q; i++){
            int mi = oq[i][0];
            int xi = oq[i][1];
            int qi = oq[i][2];
            while(ind < n && nums[ind]<=mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0){
                // nothing 
                
                ans[qi] = trie.getMax(xi);
            }
            else{
                ans[qi] = -1;
            }
        }
        return ans;
    }
};
