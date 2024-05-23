#include<bits/stdc++.h>
using namespace std;
vector<int> bubble_sort(vector<int> &v){
       
    // par example vector<int> v = {2,8,5,3,9,4,1}; //size = 7
    int k;
    for(int i = 0; i< v.size(); i++) {
        k = 0;
        /* 
        // i = 0 
        // j = 0, 2 and 8 remain intact
        // j =1, 8 and 5 swap 2 5 8 3 9 4 1
        // j = 2, 8 and 3 swap, 2 5 3 8 9 4 1 
        // j = 3, remain intact 2 5 3 8 9 4 1
        // j = 4 swap , 2 5 3 8 4 9 1
        // j =5 swap 2 5 3 8 4 1 9
        
        
        i = 1
        j = 0, 2 5 3 8 4 1 9
        j = 1, 2 3 5 8 4 1 9
        j = 2, 2 3 5 8 4 1 9
        j = 3, 2 3 5 4 8 1 9
        j = 4, 2 3 5 4 1 8 9
        
        i = 2, j< 4
        j = 0, 2 3 5 4 1 8 9
        j = 1, 2 3 5 4 1 8 9
        j = 2, 2 3 4 5 1 8 9
        j = 3, 2 3 4 1 5 8 9
        
        i = 3, j<3
        j = 0, 2 3 4 1 5 8 9
        j = 1, 2 3 4 1 5 8 9
        j = 2, 2 3 1 4 5 8 9
        
        i = 4, j<2 
        j = 0, 2 3 1 4 5 8 9
        j = 1, 2 1 3 4 5 8 9
        
        i = 5, j< 1
        j = 0, 1 2 3 4 5 8 9
        */
        
        for(int j = 0; j<v.size()-1-i; j++){ // j < 6, 5
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                k = 1;
            }
        } 
        if(k==0){
            break;
        }
    } // let's put this in a function
    return v;
}
int main() {
    // worst case - max iterations decreasing array O(N2)
    // best case - min. iterations already sorted O(N)
    /* Bubble sort - consists of swapping the elements with the next one*/
    
    for(auto &value : bubble_sort(v)){
        cout<<value<<" "<<endl;
    }
    
}
