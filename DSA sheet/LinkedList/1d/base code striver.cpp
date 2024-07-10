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
