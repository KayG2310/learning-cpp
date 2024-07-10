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


int main(){
    string one="sana", two="kimmi";
    Node *y = new Node(one, nullptr);
    Node *z = new Node(two, nullptr);
    (*y).next = z;
    cout<<y->data<<" & "<<y->next<<endl;
    cout<<z->data<<" & "<<z->next<<endl;
    cout<<y; // this is root ka memory location
    
    
}



// below is the code to convert an array to a linkedlist
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

int main(){
    /*
    string one="sana", two="kimmi";
    Node *y = new Node(one, nullptr);
    Node *z = new Node(two, nullptr);
    (*y).next = z;
    cout<<y->data<<" & "<<y->next<<endl;
    cout<<z->data<<" & "<<z->next<<endl;
    cout<<y; // this is root ka memory location
    */
    vector<string> v = {"apple", "mango", "banana", "pear"};
    Node* h = converter(v);
    cout<<h->data;
    
}


