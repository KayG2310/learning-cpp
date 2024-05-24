#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    vector<int> piles;
    piles.push_back(-1*a);
    piles.push_back(-1*b);
    piles.push_back(-1*c);
    
    int sum = 0;
    while(piles[0]!=0 && piles[1]!=0){
        sort(piles.begin(), piles.end());
        piles[0]++;
        piles[1]++;
        sum++;
        sort(piles.begin(), piles.end());
    }
    return sum;
}

int main(){
    maximumScore(6,4,4);
}
