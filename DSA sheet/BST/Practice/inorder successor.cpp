class Solution{
    private:
        
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* n = new Node(-1);
        Node* temp = root;
        
        while(temp != NULL){
            if(temp->data > x->data){
                n = temp;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return n;
        
    }
};
