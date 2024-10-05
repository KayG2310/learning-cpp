/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

Node* findPredecessor(Node* root, Node* p) {
    Node* n = new Node(-1);
	if(root == NULL) return n;
	Node* temp = root;
	while(temp != NULL){
		if(temp->data < p->data){
			n = temp;
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	return n;
}
