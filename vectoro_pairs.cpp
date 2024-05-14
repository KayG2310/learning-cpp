#include<bits/stdc++.h>
using namespace std;

// creating a function to display the elements
void Display(vector<pair<int,int>>&v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" & "<<v[i].second;
        cout<<endl;
    }
}

int main() {
    vector<pair<int,int> > v = {{1,2},{3,4}};
    Display(v);
    
    // now we'll be inputting a vector of pairs
    
    vector<pair<int,int> > v2;
    cout<<"enter size of vector of pairs: ";
    int n;
    cin>>n;
    for(int i =0; i<=n;i++){
        int x,y;
        cin>>x >>y;
        v2.push_back({x,y});
    }
    Display(v2);
    
    return 0;
}
