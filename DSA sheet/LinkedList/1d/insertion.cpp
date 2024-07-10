// insertion at head
Node* inserthead(Node* head, string element){
    Node* temp = new Node(element, head);
    return temp;
}

// insert at tail
Node* insertTail(Node* head, string element){
    if(head==NULL){
        return new Node(element);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* temp2 = new Node(element);
    temp->next = temp2;
    return head;
}

// insert anywhere including tail
Node* insertk(Node* head, string element, int k){
    if(head==NULL || k==1){
        return inserthead(head, element);
    }
    Node* temp = head;
    int i=1;
    while(temp != nullptr){
        if(i==k-1){
            Node* temp2 = new Node(element);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
    return head;
}

// insert at value 
Node* insertbeforeval(Node* head, string element, string val){
    if(head==NULL){
        return inserthead(head, element);
    }
    if(head->next == nullptr){
        return inserthead(head,element);
    }
    if(head->data == val){
        return inserthead(head,element);
    }
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data ==val){
            Node* temp2 = new Node(element);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
