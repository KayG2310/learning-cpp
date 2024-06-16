// imp for approach of avoiding unecessary loops
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        long long sum = 0;
        long long i=1;
        long long bstart=b, bend=max(1,int(b-n+1));
        if(bstart<a){
            cout<<n*a<<endl;;
        }
        else if(bend>a){
            cout<<(n*(bstart+bend))/2<<endl;
        }
        
        else {
            bstart = b;
            bend = a;
            int k = b-a+1;
            sum+=(k*(b+a))/2;
            sum+= (n-k)*a;
            cout<<sum<<endl;
    }
}
}
// 5 5 11
// 5 5 5 5 5 
// 11 10 9 8 7
