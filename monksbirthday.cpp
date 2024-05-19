/* https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // since the names should not be redundant, sets should be used.
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        // sorted lexicographically we will use normal set
        set<string> s;
        for (int i = 0; i < N; i++) {
            string name;
            cin >> name;
            s.insert(name);
        }
        for (string value :s) {
            cout<< value<<endl;
        }
    }

    return 0;
}

