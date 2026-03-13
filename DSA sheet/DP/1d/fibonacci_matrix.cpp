#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

void multiply(long long A[2][2], long long B[2][2]) {
    long long x = (A[0][0]*B[0][0] + A[0][1]*B[1][0]) % MOD;
    long long y = (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % MOD;
    long long z = (A[1][0]*B[0][0] + A[1][1]*B[1][0]) % MOD;
    long long w = (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % MOD;
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}
void power(long long M[2][2], int n) {
    long long result[2][2] = {{1,0},{0,1}}; // identity matrix
    while(n > 0) {
        if(n % 2 == 1) multiply(result, M);
        multiply(M, M); // square the matrix
        n /= 2;
    }
    // copy result back
    M[0][0] = result[0][0];
    M[0][1] = result[0][1];
    M[1][0] = result[1][0];
    M[1][1] = result[1][1];
}
long long fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long M[2][2] = {{1,1},{1,0}};
    power(M, n-1);
    return M[0][0];
}
