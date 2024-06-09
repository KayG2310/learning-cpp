#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    
    // alice wants 
    // storing cumulative sums
    vector<int>cums;
    int k =1;
    int sum =1 ;
    cums.push_back(sum);
    while(k<=n){
        k+=2;
        sum+=k;
        cums.push_back(sum);
    }
    int count = 0;
    auto ptr1 = cums.begin();
    auto ptr2 = cums.end();
    ptr2--;
    while(ptr1!=cums.end()){
        // fixed ptr1 position inner loop changes ptr2 position
        while(*ptr2> *ptr1){
            if((*ptr2)-(*ptr1)==n){
                count++;
            }
            //ptr1++;
            ptr2--;
        }
        ptr1++;
        ptr2 = cums.end();
        ptr2--;
        
    }
    return count;
}
int main() {
    // packets contain odd number of candies
    cout<<solve(45);
    
}
