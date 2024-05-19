#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>s;
    s.push(2);
    s.push(23);
    s.push(28);
    s.push(267);
    
    // to display
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
