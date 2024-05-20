/*
the algos covered are - 
1. min_element
2. max_element
3. accumulate
4. count

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin>>v[i];
    }
    int min = *min_element(v.begin(), v.end());
    cout<<"min element: "<<min<<endl;
    int max = *max_element(v.begin(), v.end());
    cout<<"max element: "<<max<<endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout<<"sum is: "<<sum<<endl;
    // count
    // find returns iterator
    string s="kamakshi";
    reverse(s.begin(), s.end());
    cout<<"reversed string is: "<<s<<endl;
}
