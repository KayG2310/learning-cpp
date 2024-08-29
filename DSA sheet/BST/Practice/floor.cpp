class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
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
};
