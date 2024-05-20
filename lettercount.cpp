#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    map<char,int>m;
    for(int i=0; i<s.length();i++){
        m[s[i]]-=1;
    }
    map<int, set<char>>m2;
    for(auto it=m.begin(); it!=m.end();it++){
        char character = (*it).first;
        int frequency = (*it).second;
        m2[frequency].insert(character);
    }
    
    auto it2=m2.begin();
    auto output2 = (*it2).second;
    for(auto &val: output2){
        cout<<val;
        break;
    }
    
}
