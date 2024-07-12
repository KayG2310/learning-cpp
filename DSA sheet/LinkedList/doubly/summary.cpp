// doubly linked list
#include<bits/stdc++.h>
using namespace std;

// here we write the code for doubly linked lists
struct Node{
    string data;
    Node* next;
    Node* prev;
    
    Node(string element, Node* next1, Node* prev1){
        data = element;
        next = next1;
        prev = prev1;
    }
    Node(string element){
        data = element;
        next = nullptr;
        prev = nullptr;
    }
};

Node* converter(vector<string>&arr){
    Node* head = new Node(arr[0]);
    Node* back = head;
    // previous of the next box is head
    for(int i=1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        back->next = temp;
        temp->prev = back;
        back = temp;
    }
    return head;
}
Node* deletehead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node* deletetail(Node*head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    // temp is now at the last 
    Node* temp2 = temp->prev;
    // temp2 holds the pentail box
    temp->prev = nullptr;
    temp2->next = nullptr;
    free(temp);
    return head;
}

Node* deletek(Node* head, int k){
    if(k==1) return deletehead(head);
    if(head==NULL) return NULL;
    int i = 1;
    Node* temp = head;
    while(temp->next != nullptr){
        if(i==k){
            break;
        }
        else{
            temp = temp->next;
        }
        i++;
    }
    //we are now at the dabba to be deleted
    Node* tempback = temp->prev;
    Node* tempforw = temp->next;
    if(tempback==NULL && tempforw==NULL){
        free(temp);
        return NULL;
    }
    // now aage peeche wale are stored
    temp->prev = nullptr;
    temp->next = nullptr;
    tempback->next = tempforw;
    if(tempforw != nullptr){
    tempforw->prev = tempback;
    }
    free(temp);
    return head;
}

void deletenode(Node* node){
    Node* backk = node->prev;
    Node* forw = node->next;
    
    if(forw == nullptr){
        backk->next = nullptr;
        node->prev = nullptr;
        // node-> next is already null
        free(node);
        return;
    }
    if(backk == nullptr){
        
    }
    node->next = nullptr;
    node->prev = nullptr;
    backk->next = forw;
    forw->prev = backk;
    free(node);
    return;
}

Node* insertbeforehead(Node* head, string element){
    Node* newhead = new Node(element);
    newhead->next = head;
    head->prev = newhead;
    return newhead;
}

Node* insertbeforetail(Node* head, string element){
    // taking care of edge cases
    if (head->next = nullptr){
        // tail = head
        return insertbeforehead(head, element);
    }
    Node* temp = head;
    Node* pentail = new Node(element);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* backbox = temp->prev;
    backbox->next = pentail;
    pentail->prev = backbox;
    pentail->next = temp;
    return head;
}

Node* insertbeforek(Node* head, string element, int k){
    if(k==1) return insertbeforehead(head, element);
    int i=1;
    Node* temp = head;
    while(temp != nullptr){
        if(i==k){
            break;
        }
        i++;
        temp = temp->next;
    }
    Node* backbox = temp->prev;
    Node* insert = new Node(element);
    backbox->next = insert;
    insert->prev = backbox;
    insert->next = temp;
    temp->prev = insert;
    return head;
    
}

void insert(Node* node, string element){
    Node* prevv = node->prev;
    Node* newn = new Node(element);
    prevv->next = newn;
    newn->prev = prevv;
    
}

Node* reverse(Node* head){
    stack<string>els;
    Node* temp = head;
    while(temp != nullptr){
        els.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp-> data = els.top();
        els.pop();
        temp = temp->next;
    }
    return head;
}
int main() {
    vector<string> arr = {"india", "pakistan","bangaldesh", "sri lanka"};
    Node* head = converter(arr);
    
    // we will print our linked list in this function
    //head = deletehead(head);
    //head = deletek(head,4);
    //head = insertbeforehead(head,"australia");
    //head = insertbeforetail(head,"england");
    head = reverse(head);
    Node* temp = head;
    while(temp != nullptr){
        cout<<"previous: "<<temp->prev<<endl;
        cout<<"next: "<<temp->next<<endl;
        cout<<"data: "<<temp->data<<endl;
        cout<<"---------------"<<endl;
        temp = temp->next;
    }
}
