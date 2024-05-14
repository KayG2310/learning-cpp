#include<bits/stdc++.h>
using namespace std;

// creating a function to display the elements
void Display(vector<int>&v){
   for(int i=0; i<v.size(); i++){
       cout<<v[i]<<" ";
   }
   cout<<endl;
}

int main() {
    int N;
    cout<<"number of vectors in vector: ";
    cin>>N;
    vector<vector<int>>v;
    for(int i=0; i<N; i++){
        int n;
        cout<<"no. of elements in your inner vector: ";
        cin>>n;
        vector<int>vin;
        for(int j=0; j<n; j++){
            int x;
            cout<<"enter n elements: ";
            cin>>x;
            vin.push_back(x);
        }
        v.push_back(vin);
    }
    
    for(int i=0; i<v.size(); i++){
        Display(v[i]);
    }
    
    return 0;
}
