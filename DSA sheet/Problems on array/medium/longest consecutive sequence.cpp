// brute force, q different from leetcode
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[9] = {10, 22, 24,20, 3,4,5,6,11};
    int n = sizeof(arr)/ sizeof(int);
    int maxi = 1;
    int longest = 1;
    for(int i=0; i<n-1; i++){
        if(arr[i]+1==arr[i+1]){
            longest++;
            maxi = longest;
            maxi = max(longest, maxi);
        }
        else{
            longest = 1;
        }
    }
   cout<<maxi;
}

// leetcode explanation ---> different interpretation
// brute force 
#include <bits/stdc++.h>
using namespace std;

bool linear(int arr[], int num, int n){
    for(int i=0; i<n;i++){
        if (arr[i]==num) return true;
    }
    return false;
}

int main() {
    int arr[] = {0,3,7,2,5,8,4,6,0,1};
    int n = sizeof(arr)/ sizeof(int);
    int longest = 1;
    for(int i=0; i<n; i++){
        int x = arr[i];
        int cnt = 1;
        while(linear(arr, x+1,n)){
            x = x+1;
            cnt++;
        }
        longest = max(longest,cnt);
    }
   cout<<longest;
}

// better approach --> sort the array, submitted on leetcode
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {0,3,7,2,5,8,4,6,0,1};
    int n = sizeof(arr)/ sizeof(int);
    sort(arr,arr+n);
    int cnt = 0;
    int lastsmol = INT_MIN;
    int longest = 1;
    for(int i=0; i<n; i++){
        if(arr[i]-1==lastsmol){
            cnt++;
            lastsmol = arr[i];
        }
        else if(lastsmol != arr[i]){
            cnt = 1;
            lastsmol = arr[i];
        }
        longest = max(longest,cnt);
    }
   cout<<longest;
}



// optimal approach --->
#include <bits/stdc++.h>
using namespace std;

int longest_succ(int nums[], int n){
    if(n==0) return 0;
    unordered_set<int> s;
    int longest = 1;
    for(int i=0; i<n; i++){
        s.insert(nums[i]);
    }
    
    // now iterate through the set of unique elements
    for(auto &it: s){
        if(s.find(it-1) == s.end()){
            // like there's no element smaller than you
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main() {
    
   cout<<longest;
}

