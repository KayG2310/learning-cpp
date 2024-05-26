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


    // for 2n+ 2 there are two unique numbers
     // again nested for loop or frequency table
    // logic XOR of two different numbers can never be zero
    // we will a xored no. we note position of set bit & find numbers from array that have set bit at that position.
    // again take xor of all
}
