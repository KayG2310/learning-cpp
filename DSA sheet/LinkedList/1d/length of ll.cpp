class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
Node* temp = head;
    int i=1;
    while(temp != nullptr){
        i++;
        temp = (*temp).next;
    }
    return i-1;
    }
};
