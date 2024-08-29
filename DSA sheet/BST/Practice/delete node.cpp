class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        // root is not null
        if(root->val == key){
            return helper(root);
        }
        TreeNode* root2 = root;
        while(root){
            if(root->val > key){
                if(root->left != nullptr && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right != nullptr && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return root2;
    }


    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        // both left side and right side exist
        TreeNode* rightChild = root->right;
        TreeNode* last = helper2(root->left);
        last->right = rightChild;
        return root->left;

    }

    TreeNode* helper2(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
};
