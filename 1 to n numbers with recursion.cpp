#include <iostream>
using namespace std;

// Function to print numbers from 1 to N using recursion
void printNos(int N) {
    // Base case: when N is 0, do nothing (stop recursion)
    if (N == 0) {
        return;
    }
    printNos(N - 1);
    
    // Print the current number N
    cout << N << " ";
}
