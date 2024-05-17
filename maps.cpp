#include<bits/stdc++.h>
using namespace std;

int main() {
    // code to write a basic map
    map<int,string> m;
    m[1] = "abc"; //O(log(n))
    m[23] = "kgf";
    m[5] = "cgg";
    m.insert({5,"momo"});
    // now we declare an iterator
    map<int,string> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout<<(*it).first<< " " <<(*it).second<<endl;
        // since it is essentially a pair
        // and we can do
        cout<<it->first<<" "<< it-> second<<endl;
    }
    
    // now we'll use the shorthand notation for the iterator
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it-> first<<" "<<it->second<<endl;
    }
    
    // find function logn
    auto itfind = m.find(5);
    if(itfind==m.end()){
        cout<<"No value";
    } else {
        cout<<itfind->first<<" "<<itfind->second;
    }
    
    // end function
    m.erase(1); //logn
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it-> first<<" "<<it->second<<endl;
    }
    m.erase(itfind);
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it-> first<<" "<<it->second<<endl;
    }
    return 0;
}
