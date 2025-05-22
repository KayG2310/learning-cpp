// brute force - make a positive array, make a negative array, you can replace in place sc = O(N) TC = O(2N)
// we cannot reduce the extra space
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[6] = {-7,-1,-5,3,6,4};
    int n = sizeof(arr)/sizeof(int);
    int ans[6];
    int pos=0, neg = 1;
    for(int i=0; i<n;i++){
        if(arr[i]>0){
            ans[pos] = arr[i];
            pos+=2;
        }
        else {
            ans[neg] = arr[i];
            neg+=2;
        }
    }
    
    for(int i=0; i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}
/*
tc = O(N), sc = O(N)
*/

//variety 2 --> if extra elements of same parity left add them to beginning
// here brute force solution can't work because that relied on the fact that positive and negative numbers are same





optimal
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}


//if unequal 
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 6;
  vector<int> A {1,2,-4,-5,3,4};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
