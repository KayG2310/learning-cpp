#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[15] = {4,1,2,9,7,21,23,67,8,456,6,32,65,98,465};
    auto start_time = clock();
    sort(a,a+15);
    auto end_time = clock();
    cout<< end_time - start_time;
    
    return 0;
}
