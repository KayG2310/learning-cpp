struct Node{
    Node *links[26];
    bool flag = false;
    bool containsch(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag = true;
    }
};
class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    // tc = len of word
    void insert(string word) {
        Node* node = root; // dummy variable
        for(int i=0; i<word.length(); i++){
            if(node->containsch(word[i])==0){
                // is not there
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
    
    // O(len)
    bool search(string word) {
        Node* node = root; // start with root node
        for(int i=0; i<word.length(); i++){
            if(node->containsch(word[i])){
                // if it exists
                node = node->get(word[i]);
            }
            else return false;
        }
        if(node->flag == true) return true;
        return false;
    }
    
    // O(len)
    bool startsWith(string word) {
        Node* node = root; // start with root node
        for(int i=0; i<word.length(); i++){
            if(node->containsch(word[i])){
                // if it exists
                node = node->get(word[i]);
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
