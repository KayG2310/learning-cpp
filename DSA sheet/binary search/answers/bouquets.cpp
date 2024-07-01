class Solution {
private:
bool possible(vector<int>&bloomDay, int m, int k, int day){
            // inner function to check if possible or not
    long long our = 0;
    for(int i=0; i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            our++;
            if(our%k==0){
                m-=1;
                if(m==0) return true;
            }
        }
        
        else{
            our=0;
        }
    }
    if(m==0) return true;
    return false;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //long long int product = m*k;
        if(m>bloomDay.size()/k) return -1;
        //if(product==bloomDay.size()) return *max_element(bloomDay.begin(), bloomDay.end());

        // now we move to the actual problem
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        // keep min-ing from this
        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long mid = 0;
        long long ans = INT_MAX;
        while(low<=high){
            mid = low+ (high-low)/2;
            bool check = possible(bloomDay,m,k,mid);
            cout<<check<<endl;
            cout<<low<<" "<<high<<" "<<mid<<endl;
            if(check){
                ans = min(ans, mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};
/*
dry run 
1e9, 1e9 m=1, k=1
high = low, mid = 1e9

*/
