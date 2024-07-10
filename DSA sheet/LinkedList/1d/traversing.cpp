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
    vector<string> v = {"apple", "mango", "banana", "pear"};
    Node* head = converter(v);
    Node* temp = head;
    int i=1;
    cout<<"beginning is: "<<temp<<endl;
    while(temp != nullptr){
        cout<<"data no.: "<<i<<endl;
        cout<<"value: "<<temp->data<<endl;
        cout<<"memory: "<<temp->next<<endl;
        cout<<"--------------"<<endl;
        i++;
        temp = (*temp).next;
    }
    cout<<i-1;

    // to check if an element is present, check it during traversal
}
