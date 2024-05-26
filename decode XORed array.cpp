#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {
    // first is the first element of the outputted vector
    // we will be given the encoded array, we need to find the decoded one
    // it was seen that the XOR of first and first of encoded gave arr[1]
    int size = encoded.size();
    vector<int>ans(size+1);
    ans[0] = first;
    for(int i=1; i<=size; i++){
        ans[i] = encoded[i-1] ^ ans[i-1];
    }
    return ans;
}

int main() {
   vector<int> v = {6,2,7,3};
   decode(v,4);
}
