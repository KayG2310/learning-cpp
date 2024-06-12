#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rev = 0;
    while(n){
        int lastdigit = n%10;
        n = n/10;
        rev = (rev*10)+lastdigit;
    }
    cout<<rev;
}
