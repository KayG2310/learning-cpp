#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("Dan");
    q.push("John");
    q.push("Mycroft");
    while(!q.empty()){
        cout<<q.front()<<" --> ";
        q.pop();
    }
}
