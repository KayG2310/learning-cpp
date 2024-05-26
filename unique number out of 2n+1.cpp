#include<bits/stdc++.h>
using namespace std;

int main() {
    // given 2n+1 numbers, every number comes twice except one, find it
    // approach 1 - nested for loop
    // approach 2 - frequency table
    // XOR of two numbers is 0. 
    // a ^ b ^ a = b
    // to find the unique element we just have to take the XOR of all, resulting is our ans
    vector<int>v = {1,2,3,4,3,1,2};
    int num;
    for(int i=0; i< v.size(); i++){
        num = num ^ v[i];
    }
    cout<<num;
}
