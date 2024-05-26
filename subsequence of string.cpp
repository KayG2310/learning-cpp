#include<bits/stdc++.h>
using namespace std;

int main() {
    // subsequences of a string
    string word = "abc";
    vector<char> letters;
    for(int i=0; i< word.length(); i++){
        letters.push_back(word[i]);
    }
     // letters = a b c
     for(int i=0; i< pow(2, letters.size()); i++){ // total subsets
     int x = i;
         for(int j = 0; j<letters.size(); j++){
             int lastbit = x&1;
             if(lastbit==1){
                 cout<<letters[letters.size()-1-j];
             }
             x = x>>1;
             
         } // end of inner for loop
         cout<<endl<<"this was subset: "<<i+1<<endl;
     } // now i = 2
}
// gives reverse string, can use array or something
