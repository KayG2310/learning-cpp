//leetcode
#include<bits/stdc++.h>
using namespace std;

vector<int> kclosest(vector<int> arr, int k, int x) {
    vector<int> answer;
    int n = arr.size(); //n = 5
    map<int, vector<int>> m;
    for(int i=0; i<n; i++){
        int diff = arr[i]-x;
        if(diff<=0){
            diff = -1*diff; //absolute value of differences
            
        }
        m[diff].push_back(arr[i]); 
        // now corresponding to a particular difference, the vector stores the elements.
    
    }
    
    // let's display our map
    for(auto it= m.begin(); it!=m.end(); it++){
        vector<int> numbers = (*it).second;
            for(auto &value: numbers){
                cout<<(*it).first<<" & "<<value<<endl;
            }
    }
    
    // d = 2 ; 1
    // d = 3 ; 2
    // d = 4 ; 3
    // d = 5 ; 4
    // d = 6 ; 5
    // answer = {1}, k = 3
    // answer = {1,2}, k = 2
    // answer = {1,2,3} k = 1
    // answer = {1,2,3,4} k = 0, breaks.
    
        for(auto it= m.begin(); it!=m.end(); it++){
            vector<int> numbers = (*it).second;
            for(auto &value: numbers){
                answer.push_back(value);
                k--;
                if(k==0){break;}
            }
            if(k==0){break;}
        }
    
    
    sort(answer.begin(), answer.end());
    return answer;
    
}

int main(){
    vector<int> v= {1,2,3,4,5};
    int k = 4;
    int x = -1;
    for(auto &val: kclosest(v,4,-1)){
        cout<< val<<" ";
    }
}
