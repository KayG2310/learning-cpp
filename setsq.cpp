#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin>>Q;
    multiset<long long>s;
    for(int i=0; i<Q; i++){
        int y;
        long long x;
        cin>>y>>x;
        if(y==1){
            s.insert(x);
        } else if(y==2){
            auto it = s.find(x);
            if(it!=s.end()){
                s.erase(it);
            } 
        } else {
            auto it2 = s.find(x);
            if(it2!=s.end()){
                cout<<"Yes"<<endl;
            } else{
                cout<<"No"<<endl;
            }
            
        }
        
    }
 
}
