// just inserting the functions here

Node* deletehead(Node* head){
    if(head ==NULL) return head;
    Node* temp = head;
    head = (*head).next;
    free(temp);
    // or delete temp;
    return head;
}

// deleting the tail
Node* deletetail(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* temp = head;
    while((temp->next)->next != nullptr){
        temp = (*temp).next;
    }
    Node* temp2 = temp->next;
    temp->next = nullptr;
    free(temp2);
    return head;
}



