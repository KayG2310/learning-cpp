// brute force method --> n2 * whatever is map complexity
#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    // brute force method
    int maxlen = 0;
    unordered_map<char, int> freq;
    for(int i=0; i<str.length(); i++){
        freq.clear();
        for(int j=i; j<str.length(); j++){
            freq[str[j]]++;
            if(freq.size() <=k){
                maxlen = max(maxlen, j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}

// better 2n, k
#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    // better method
    int maxlen = 0, l=0, r=0;
    unordered_map<char, int> freq;
    while(r<str.length()){
        freq[str[r]]++;
            
        while(freq.size()>k){
            freq[str[l]]--;
            if(freq[str[l]] == 0) freq.erase(str[l]);
            l++;
        }
        if(freq.size()<=k) maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}


// best n 
#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    // better method
    int maxlen = 0, l=0, r=0;
    unordered_map<char, int> freq;
    while(r<str.length()){
        freq[str[r]]++;
            
        if(freq.size()>k){
            freq[str[l]]--;
            if(freq[str[l]] == 0) freq.erase(str[l]);
            l++;
        }
        if(freq.size()<=k) maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}
