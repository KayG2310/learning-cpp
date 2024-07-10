class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp = head;
        for(int i=0; i<n; i++){
            if(temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }
};
