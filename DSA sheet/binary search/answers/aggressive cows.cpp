// here, again, it depends on our checker function and since we need maximum possible answer, we return high
#include<bits/stdc++.h>
using namespace std;

bool canweplace(vector<int>&stalls, int cows,int dist){
    int cur_cows = 1, last = stalls[0];
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]-last>=dist){
            cur_cows++;
            last = stalls[i];
        }
        if(cur_cows>=cows) return true;
        // still inside and all covered, yes
    }
    return false;
}

int maxdist(vector<int>&stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size()-1]-stalls[0], mid = 0;
    int ans = INT_MIN;
    while(low<=high){
        mid = (low+high)/2;
        if(canweplace(stalls, cows,mid)==true){
            ans = max(ans, mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int stalls,cows;
        cin>>stalls>>cows;
        vector<int>stallss(stalls);
        for(int i=0; i<stalls; i++){
            cin>>stallss[i];
        }
        cout<<maxdist(stallss, cows)<<endl;
    }
}
