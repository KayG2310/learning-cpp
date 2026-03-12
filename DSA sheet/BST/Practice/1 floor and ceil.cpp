class Solution{
public:
    int floor(Node* root, int x) {
        int floor = -1;
        while(root){
            if(root->data == x){
                floor = root->data;
                return floor;
            }
            else if(root->data <x){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    }
    int findCeil(Node* root, int input) {
        if (root == NULL) return -1;
        int ceil = -1;
        while(root){
            if(root->data == input){
                ceil = root->data;
                return ceil;
            }
            else if(root->data >input){
                ceil = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ceil;
    }
};


