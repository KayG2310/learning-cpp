#include<bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node* next;
    
    Node(string userdata, Node* usernext){
        data = userdata;
        next = usernext;
    }
    Node(string userdata){
        data = userdata;
        next = nullptr;
    }
};

// we cannot return the entire linked list so we return the pointer to the head

Node* converter(vector<string>&nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    // it initially points at the head
    for(int i=1; i<nums.size(); i++){
        Node* temp = new Node(nums[i]);
        (*mover).next = temp;
        mover = temp;
    }
    return head;
    
}

Node* deletehead(Node* head){
    Node* temp = head;
    head = (*head).next;
    free(temp);
    // or delete temp;
    return head;
}

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

int findlen(Node* head){
    Node* temp = head;
    int i=1;
    while(temp != nullptr){
        i++;
        temp = (*temp).next;
    }
    return i-1;
}

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

Node* inserthead(Node* head, string element){
    Node* temp = new Node(element, head);
    return temp;
}

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

int main(){
    vector<string> v = {"apple", "mango", "banana", "pear"};
    Node* head = converter(v);
    //head = deletek(head,2);
    //head = deleteEl(head, "pear");
    //head = inserthead(head, "litchi");
    //head = insertTail(head, "apricot");
    //head = insertk(head, "JACKFRUIT",3);
    head = insertbeforeval(head, "jackfruit", "pear");
    Node* temp = head;
    
    cout<<"beginning is: "<<temp<<endl;
    while(temp != nullptr){
        cout<<"value: "<<temp->data<<endl;
        cout<<"memory: "<<temp->next<<endl;
        cout<<"--------------"<<endl;
        temp = (*temp).next;
    }
}
