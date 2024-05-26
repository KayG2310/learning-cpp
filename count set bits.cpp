#include<bits/stdc++.h>
using namespace std;


int main() {
  // counting set_bits
  int count;
  int n;
  cin>>n;
  while(n){
      int lastbit = (n&1);
      count+=lastbit;
      n=n>>1;
  }
  cout<<count;
  
  // second way 

  int ans=0;
  while(n){
      n = (n&(n-1));
      // this method removes the last set bit as it would differ by 1 
      // n = 7
      // 111 & 110 = 110 = 6
      // 110 & 101 = 100 = 4
      // 4 & 3 = 100 & 011 = 0
      ans+=1;
  }
  cout<<ans;
  
}
