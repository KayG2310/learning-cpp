class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == x){
                if(temp == head){
                    head = temp->next;
                }
                Node* nextnode = temp->next;
                Node* prevnode = temp->prev;
                if(nextnode != nullptr){
                    nextnode->prev = prevnode;
                }
                if(prevnode != nullptr){
                    prevnode->next = nextnode;
                }
                free(temp);
                temp = nextnode;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};
