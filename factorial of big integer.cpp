#include<bits/stdc++.h>
using namespace std;


int main() {
 int n;
 cin>>n;
 
 // we can randomise the number of digits as per constraints in the question
 vector<int> v(1000,0);
 v[0] = 1;
 int size = 1;
 int carry = 0;
 for(int i = 2;i <=n;i++){
     
     for(int j = 0; j<size; j++){
         int dm = v[j]* i + carry;
         v[j] = dm%10;
         carry = dm/10;
         
     }
     while(carry!=0){
     v[size] = carry%10;
     carry = carry/10;
     size++;
 }
 }
 
 
 
 for (int k = size - 1; k >= 0; k--) {
        cout << v[k];
    }
}
