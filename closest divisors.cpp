#include<bits/stdc++.h>
using namespace std;
vector<int> closestDivisors(int num) {
      long long num1,num2;
      num1 = num+1;
      num2 = num+2;
      
      // logic root n is the closest 
      vector<int>ans(2);
      pair<int,int>num1p;
      pair<int,int>num2p;
      for(int i=pow(num1,0.5)/1; i>=1;i--){
          if(num1%i==0){
              num1p.first = i;
              num1p.second = num1/i;
              break;
          }
      }
      for(int i=pow(num2,0.5)/1; i>=1;i--){
          if(num2%i==0){
              num2p.first = i;
              num2p.second = num2/i;
              break;
          }
      }
      int abs1 = abs(num1p.first - num1p.second);
      int abs2 = abs(num2p.first - num2p.second);
      if(abs1>abs2){
          ans[0]=num2p.first;
          ans[1]=num2p.second;
      }
      else {
          ans[0]=num1p.first;
          ans[1]=num1p.second;
      }
      sort(ans.begin(), ans.end());
      return ans;
}
int main() {
    // packets contain odd number of candies
    vector<int> a = closestDivisors(8);
    cout<<a[0]<<" "<<a[1];
    
}
