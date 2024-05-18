
#include <bits/stdc++.h>
using namespace std;
void print(set<string> &s){
    // &s so that a copy is not created
    for(auto it= s.begin(); it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    for(string value:s){
        cout<< value << endl;
    }
}
void print(multiset<string> &s){
    // &s so that a copy is not created
    for(auto it= s.begin(); it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    for(string value:s){
        cout<< value << endl;
    }
}
int main() {
   set<string> s;
   // can be nested 
   // a normal set is ordered
   s.insert("hello world");
   s.insert("this is a set");
   s.insert("ayo");
   auto it2 = s.find("ayo");
   if(it2!= s.end()){
       cout<< (*it2); //logn 
   }
   print(s);


    // unordered sets
    /* question : - in each query you are given a string, if it is present 
    print yes else no */
    unordered_set<string>s2;
    int n;
    cout<<" enter strings to be put in a set";
    cin>>n;
    for(int i = 0; i<n; i++){
        cout<<"enter string"<<i;
        string x;
        cin>>x;
        s2.insert(x);
    }
    int q;
    cout<<" enter queries";
    cin>>q;
    for(int i = 0; i<q; i++){
        cout<<"enter string"<<i;
        string x;
        cin>>x;
        auto it = s2.find(x);
        if(it!=s2.end()){
            cout<<"yes"<<endl;
        } else{
            cout<<"no"<<endl;
        }
    }
    // multiset
    multiset<string>s3;
    s3.insert("hey");
    s3.insert("good");
    s3.insert("hey");
    print2(s3);
    return 0;
