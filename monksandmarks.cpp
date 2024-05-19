#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, multiset<string>>m; // if names are duplicate
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        string name;
        int marks;
        cin>>name>>marks;
        m[marks].insert(name);
    }
    auto it = m.end();
    it--; //can use negative marks
    while(true){
        auto &name = (*it).second;
        int marks = (*it).first;
        
        
        for(auto &val:name){
            cout<<val<<" "<<marks <<endl;
            
        }
        if(it== m.begin()){
            break;
        } else{
            it--;
        }
    }
}
