#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char, int> frequency;
    for(int i = 0; i<s.length();i++){
        frequency[s[i]]++;
    }
    int count = 0;
    int flag = -2;
    for(int trav=0; trav<s.length(); trav++){
        char char_to_check = s[trav];
        auto confirm_iterator = frequency.find(char_to_check);
        
        if((*confirm_iterator).second==1){
            cout<<trav;
            flag = 100;
            break;
        }
    }
    
    if(flag==-2){
        cout<<(-1);
    }
}
