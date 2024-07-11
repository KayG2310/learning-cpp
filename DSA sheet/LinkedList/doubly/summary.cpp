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
    node->next = nullptr;
    node->prev = nullptr;
    backk->next = forw;
    forw->prev = backk;
    free(node);
}
int main() {
    vector<string> arr = {"india", "pakistan","bangaldesh", "sri lanka"};
    Node* head = converter(arr);
    
    // we will print our linked list in this function
    //head = deletehead(head);
    head = deletek(head,4);
    Node* temp = head;
    while(temp != nullptr){
        cout<<"previous: "<<temp->prev<<endl;
        cout<<"next: "<<temp->next<<endl;
        cout<<"data: "<<temp->data<<endl;
        cout<<"---------------"<<endl;
        temp = temp->next;
    }
}
