Node* deleteEl(Node* head, string element){
    if(head==NULL) return head;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->next->data == element){
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            break;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
