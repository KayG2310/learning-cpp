#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    int ew = 0;
    int cp = 0; // cnt prefix
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void increaseEnd(){ ew++;}
    void increasecp(){ cp++;}
    void decreaseend(){
        ew--;
    }
    void decreasecp(){ cp--; }

};
class Trie{
    private:
        Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();

    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->contains(word[i])==false){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasecp();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->contains(word[i])== false) return 0;
            node = node->get(word[i]);
        }
        return node->ew;
        
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->contains(word[i])== false) return 0;
            node = node->get(word[i]);
        }
        return node->cp;
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            // if(node->contains(word[i])== false) return 0;
            node = node->get(word[i]);
            node->decreasecp();
        }
        return node->decreaseend();
    }
};
