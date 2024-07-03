#include<bits/stdc++.h>
using namespace std;

bool canweplace(vector<int>&pages, int boys,int maxpages){
    int cur_boys = 1, last=pages[0];
    for(int i=1; i<pages.size(); i++){
        if(last+pages[i]>maxpages){
            cur_boys++;
            last = pages[i];
        }
        else{
            last +=pages[i];
        }
        if(cur_boys>boys) return false;
    }
    return true;
}

int maxdist(vector<int>&pages, int boys){
    if(pages.size()<boys) return -1;
    if(pages.size()==boys) return *max_element(pages.begin(), pages.end());
    int low = *max_element(pages.begin(), pages.end()), high = accumulate(pages.begin(), pages.end(),0), mid = 0;
    int ans = INT_MAX;
    while(low<=high){
        mid = (low+high)/2;
        if(canweplace(pages, boys,mid)==true){
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
