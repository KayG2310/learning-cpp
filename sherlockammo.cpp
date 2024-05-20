#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,multiset<string>>m;
    for(int i=0;i<n;i++){
        string name;
        int jealousy;
        cin>>name>>jealousy;
        m[-1*jealousy].insert(name);
    }
    for(auto it=m.begin(); it!=m.end();it++){
        auto &na = (*it).second;
        int jea = (*it).first;
        for(auto &final:na){
            cout<<final<<" "<<(-1*jea)<<endl;
        }
    }
 
}
