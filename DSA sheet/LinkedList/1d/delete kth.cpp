Node* deletek(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        return deletehead(head);
    }
    else if(k==findlen(head)){
        return deletetail(head);
    }
    else if(k>1 && k< findlen(head)){
        // this is where our actual funcrion runs
        Node* temp = head;
        int i=1;
        while(temp != nullptr){
            if(i==k-1){
                if(temp->next->next != nullptr){
                    Node* temp2 = temp->next;
                    temp->next = temp->next->next;
                    free(temp2);
                    break;
                }
                else{
                    Node* temp2 = temp->next;
                    temp->next = nullptr;
                    free(temp2);
                    break;
                }
            }
            else{
            temp = (*temp).next;
            }
            i++;
        }
        return head;
    }
    else{
        return head;
        // deletion not possible
    }
}
