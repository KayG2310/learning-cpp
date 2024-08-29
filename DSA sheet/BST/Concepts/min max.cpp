// User function Template for C++

// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL) return -1;
        while(root->left != NULL){
            root = root->left;
        }
        return root->data;
    }
};



class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL) return -1;
        while(root->right != NULL){
            root = root->right;
        }
        return root->data;
    }
};
