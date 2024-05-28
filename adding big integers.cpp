#include<bits/stdc++.h>
using namespace std;


int main() {
 // addition of numbers using arrays
 string n1, n2;
 cin>>n1>>n2;
 string num1, num2;
 if(n1.length()>=n2.length()){
     // using strings
      num2 = n1;
      num1 = n2;
 }
 else
 { 
      num1 = n1;
  num2 = n2;
     
 }
 string result="";
 reverse(num1.begin(), num1.end());
 reverse(num2.begin(), num2.end());
 int carry = 0;
 for(int i = 0 ; i< num1.length(); i++){
     int d1 = num1[i] - '0'; // subtraction of ascii values
     int d2 = num2[i] - '0';
     int ds = (d1+d2+carry)%10;
     int carry = (d1+d2+carry)/10;
     result.push_back(ds+'0');
 }
 for(int i = num1.length() ; i< num2.length(); i++){

     int d2 = num2[i] - '0';
     int ds = (d2+carry)%10;
     int carry = (d2+carry)/10;
     result.push_back(ds+'0');
 }
 
 if(carry!=0){
     result.push_back(carry);
 }
 reverse(result.begin(), result.end());
 cout<<result;
}
