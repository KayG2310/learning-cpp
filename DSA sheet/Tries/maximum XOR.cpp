// brute force n^2 gives TLE 
class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                ans = max(ans, nums[i]^nums[j]);
            }
        }
        return ans;
    }
};

// using tries 
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
public:
    Node* root;
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

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it: nums){
            trie.insert(it);
        }
        int maxi = 0;
        for(auto &it : nums){
            maxi = max(maxi, trie.getMax(it));

        }
        return maxi;
    }
};
