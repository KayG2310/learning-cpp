#include<bits/stdc++.h>
using namespace std;
bool canweplace(vector<int>&boards, int painters,int maxpages){
    long long cur_painters = 1, last=boards[0];
    for(int i=1; i<boards.size(); i++){
        if(last+boards[i]>maxpages){
            cur_painters++;
            last = boards[i];
        }
        else{
            last +=boards[i];
        }
        if(cur_painters>painters) return false;
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int painters) {
    int n = boards.size();
    if(n==painters) return *max_element(boards.begin(), boards.end());
    int low = *max_element(boards.begin(), boards.end()), high = accumulate(boards.begin(), boards.end(),0), mid = 0;
    int ans = INT_MAX;
    while(low<=high){
        mid = (low+high)/2;
        if(canweplace(boards, painters,mid)==true){
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> board = {2, 1, 5, 6, 2, 3};
    cout<<findLargestMinDistance(board, 2);
}
