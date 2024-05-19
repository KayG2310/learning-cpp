/* https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/?fbclid=IwAR1n1FJUNpWIeq7dHY-HytoqqE1nbK9gD4jMjI2UWGTPE8GF4kHROCb7ouA*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;
    while (T--) {
        long long N, M;
        cin >> N >> M;
        unordered_set<long long> s;
        for (long long i = 0; i < N; i++) {
            long long candy;
            cin >> candy;
            s.insert(candy);
        }
        for (long long i = 0; i < M; i++) {
            long long candy;
            cin >> candy;
            if (s.find(candy) != s.end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
                s.insert(candy); 
            }
        }
    }

    return 0;
}

