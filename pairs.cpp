// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int,char>p;
    p = {2,'a'};
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    // p = make_pair(2,'m')
    
    pair<int,char>p1 = p;
    p1.second = 'b';
    cout<<p1.second<<endl;
    // this just created a copy, so of course changes in p1 won't be reflected in p

    pair<int,char>&p2 = p;
    p2.second = 'k';
    cout<<p.second<<endl;
    // & is address of object
    // * dereferencing operator
    // points to p
    
    
    // pairs of arrays
    int a[3] = {1,2,3};
    int b[3] = {5,6,7};
    pair<int,int> array_pair[3];
    array_pair[0] = {1,6};
    array_pair[1] = {2,7};
    array_pair[2] = {3,5};
    swap(array_pair[0], array_pair[2]);
    for(int i = 0 ; i<3 ; i++){
        cout<<array_pair[i].first<< " " <<array_pair[i].second<<endl;
    }
    
    // to take as input
    
    pair<int,int>p4;
    cin>>p4.first;
    cin>>p4.second;
    cout<<p4.first<<" "<<p4.second;
    
    return 0;
}
