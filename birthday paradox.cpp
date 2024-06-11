#include <bits/stdc++.h>
using namespace std;
// birthday paradox

int main() {
    int people = 1;
    float num = 365;
    float denom = 365;
    float diff_prob = 1;
    while(diff_prob>0.0000000003){
        diff_prob = diff_prob*(num/denom);
        cout<<"people: "<<people<<", prob of same bday: "<<(1-diff_prob)<<endl;
        num-=1;
        people++;
    }
}
