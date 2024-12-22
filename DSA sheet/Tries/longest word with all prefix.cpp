#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node; // assigning as per required 
    }
    void setend(){
        flag = true;
    }
    bool end(){
        return flag;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string &word){
            Node* node = root;
            for(int i=0; i<word.length(); i++){
                if(node->containsKey(word[i])==false){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setend();
        }
        bool check(string &word){
            bool fl = true;
            Node* node = root;
            for(int i=0; i<word.length(); i++){
                if(node->containsKey(word[i])){
                    // if it exists
                    node = node->get(word[i]);
                    if(node->flag == false) return false;
                }
                else return false;
            }
            return true;
        }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }
    // inserted all the words
    string longest = "";
    for(auto &it: a){
        if(trie.check(it)){
            if(it.length()>longest.length()){
                longest = it;
            }
            else if(it.length()==longest.length() && it<longest){
                longest = it;
            }
            // no case for a lesser length
        }
    }
    if(longest.length()==0) return "None";
    return longest;
}
// tc = n*len
