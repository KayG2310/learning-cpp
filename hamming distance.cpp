#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int count = 0;
    while (x > 0 || y > 0) {
        int bit_x = x & 1;
        int bit_y = y & 1;

        if (bit_x != bit_y)count++;
        
        x = x >> 1;
        y = y >> 1;
    }
    return count;
}
