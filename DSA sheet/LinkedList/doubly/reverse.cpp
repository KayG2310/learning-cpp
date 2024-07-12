// technique 1 : using stack, code in summary

// technique 2: sapping
Node* swapping(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //meaning there's only one box or none at all
    
    Node* temp = head;
    Node* lastback = nullptr;
    while(temp != nullptr){
        lastback = temp->prev;
        temp->prev = temp->next;
        temp->next = lastback;
        temp = temp->prev;
    }
    return lastback->prev;
}
