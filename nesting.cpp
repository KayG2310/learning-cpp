#include<bits/stdc++.h>
using namespace std;
int main(){
    map<pair<string,string>, vector<int>>m;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string fn,ln;
        int num;
        cin>>fn>>ln>>num;
        for(int j=0; j<num; j++){
            int num2;
            cin>>num2;
            m[{fn,ln}].push_back(num2);
        }
    }
    for(auto &pr: m){
        cout<<pr.first.first<<" . "<<pr.first.second<<endl;
        for(int k=0; k<pr.second.size(); k++){
            cout<<pr.second[k]<<" , ";
        }
    }
}
