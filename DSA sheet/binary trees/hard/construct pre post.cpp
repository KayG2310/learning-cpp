// Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Recursive function to construct binary
// tree from preorder and postorder
Node* constructTreeUtil(vector<int> &pre, vector<int> &post, int &preIndex,
                        int l, int h, int size) {
    if (preIndex >= size || l > h)
        return nullptr;

    // Create root node from current preorder element
    Node* root = new Node(pre[preIndex++]);

    // If there is only one element, return it as leaf node
    if (l == h)
        return root;

    // Find the next preorder element in postorder
    // to split left and right subtrees
    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == post[i])
            break;

    if (i <= h) {
        
        // Recursively construct left and right subtrees
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

// Function to construct Binary Tree from preorder and postorder
Node* constructTree(vector<int> &pre, vector<int> &post) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, preIndex, 0, pre.size()-1, pre.size());
} 
