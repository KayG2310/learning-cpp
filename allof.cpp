#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>v={1,2,3};
    cout<<all_of(v.begin(),v.end(), [](int x){return x>0;});
    // even if one of the values is negative, it will return 0
    // it's not necessary to just insert a lambda function as the third
    // argument, can pass another function of boolean type as well, similarly any_of, none_of
    
}
