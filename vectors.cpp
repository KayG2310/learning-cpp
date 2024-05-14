#include<bits/stdc++.h>
using namespace std;
// creating a function to display the contents of a vector

void Display(vector<int>v){
    for(int i = 0; i< v.size(); i++){
        // v.size O(1)
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main() {
    vector<int>v;
    // vector<int>v(5); size 5 vector by default elements will be 0
    // since the size is not defined, let's input it by the user
    int n;
    cin>>n;
    for(int i = 0; i<=n; i++){
        int x;
        cin>>x;
        v.push_back(x); // time complexity is O(1)
        // appends to the end of the vector
    
    }
    Display(v);
    // if you put line 24 in the for loop you can see that the vector size is dynamic
    
    
    vector<char>v2(4);
    for(int i=0; i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    // defining a size does not mean you cannot change it
    
    vector<int>v5(5,10);
    Display(v5);
    // vector of size 5 with entries 10
    
    // you can create a copy by vector<int>v6=v and so on that the changes in v6 won't be there in v time complexity O(n) 
    
    // realizing that copying is a time expensive operation, we should avoid passing v in the for loop for display function. so we are going to do it as 
    // void Display(vector<int>&v) , here that saves time
    
    return 0;
}
