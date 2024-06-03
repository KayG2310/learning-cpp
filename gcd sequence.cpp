#include <bits/stdc++.h>
using namespace std;

int gcd(int num1, int num2){
    
    if(num1<num2){
        swap(num1, num2);
    }
    if(num2==0){
        return num1;
    }
    return gcd(num2, num1%num2);
    
}

int main() {
   int t;
   cin>>t;
   while(t--){
       int outerflag=0;
       //cout<<gcd(36,24); // gcd function is working
       int n;
       cin>>n;
       vector<long long>a(n);
       for(int i=0; i<n; i++){
           cin>>a[i];
       }

      for(int i=0; i<n; i++){
          // testing the current element
          vector<long long>acopy = a;
          acopy.erase(acopy.begin()+i);
          // turn by turn remove one element
          vector<long long>bcopy(n-2);
          for(int j=0; j<n-2; j++){
           bcopy[j] = gcd(acopy[j], acopy[j+1]);
            }
            vector<long long>bbb = bcopy;
            sort(bbb.begin(), bbb.end());
                   int innerflag = 0;
            for(int k=0; k<bbb.size();k++){
                if(bbb[k]!=bcopy[k]){
                    innerflag +=1;
                }
            }
            if(innerflag==0){
                outerflag=2; //ek mil gya
                break;
            }
            
      }
          if(outerflag==0){
                    cout<<"no"<<endl;
       
                }
          else{
                    cout<<"yes"<<endl;
                    
                }
           
       
   }
}
