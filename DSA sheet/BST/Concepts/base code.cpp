#include <bits/stdc++.h>
using namespace std;
#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if(root == NULL) {
        return new TreeNode(val);
    }
    if(val < root->value) {
        root->left = insert(root->left, val);
    }
    else if(val > root->value) {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* inorder_successor(TreeNode* root) {
    if (root == NULL || root->left == NULL) return root;
    return inorder_successor(root->left);
}

TreeNode* remove(TreeNode* root, int val) {
    if (root == NULL) return root;
    if (val < root->value) {
        root->left = remove(root->left, val);
    }
    else if (val > root->value) {
        root->right = remove(root->right, val);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        if (root->left == NULL || root->right == NULL) {
            TreeNode* child;
            if(root->left != NULL){
                child = root->left;
            }
            else {
                child = root->right;
            }
            delete root;
            return child;
        }
        TreeNode* successor = inorder_successor(root->right);
        root->value = successor->value;
        root->right = remove(root->right, successor->value);
    }
    return root;
}

TreeNode* search(TreeNode* root, int target) {
    if(root == NULL || root->value == target) return root;
    if(target > root->value) {
        return search(root->right, target);
    }
    return search(root->left, target);
}
void inorder(TreeNode* root) {
    // Left, Node, Right
    // An inorder traversal of BST gives the elements in sorted order
    if(root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    cout<<"MENU"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Inorder Traversal"<<endl;
    cout<<"5. Exit"<<endl;
    TreeNode* root = NULL;
    while(true) {
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1) {
            int val;
            cout<<"Enter the value to insert: ";
            cin>>val;
            root = insert(root, val);
        }
        else if(choice == 2) {
            int val;
            cout<<"Enter the value to delete: ";
            cin>>val;
            root = remove(root, val);
        }
        else if(choice == 3) {
            int val;
            cout<<"Enter the value to search: ";
            cin>>val;
            TreeNode* node = search(root, val);
            if(node == NULL) {
                cout<<"Value not found"<<endl;
            }
            else {
                cout<<"Value found"<<endl;
            }
        }
        else if(choice == 4) {
            cout<<"Inorder Traversal: ";
            inorder(root);
            cout<<endl;
        }
        else if(choice == 5) {
            break;
        }
        else {
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
