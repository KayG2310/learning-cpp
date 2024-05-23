#include<bits/stdc++.h>
using namespace std;

// creating a function to display the elements
void Display(vector<int>&v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
        
    }
    cout<<endl;
}

int main() {
    // if inputting from user, we must understand that this is an array, its size must be defined. So we firstly decide how many vectors our array contains.
    
    int N;
    cout<< " how many vectors do you want inside array?";
    cin>> N;
    vector<int>v[N];
    for(int j=0; j<N; j++){
        int n;
        cin>>n;
        vector<int>vin;
        for(int k=1; k<=n; k++){
            int x;
            cin>>x;
            v[j].push_back(x);
            
        }
       
    }
    
    for(int m=0; m< N; m++){
        Display(v[m]);
    }
    return 0;
}
