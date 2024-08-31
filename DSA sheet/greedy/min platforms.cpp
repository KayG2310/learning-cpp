int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }
// above is brute force solution, failed in gfg

// optimal code, tc = 2n + 2nlogn, sc = 1
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int maxcnt = 0, cnt = 0;
    	sort(dep, dep+n);
    	sort(arr, arr+n);
    	int a = 0, d = 0;
    	while(a<n && d<n){
    	    if(arr[a]<=dep[d]){
    	        cnt++;
    	        a++;
    	    }
    	    else{
    	        cnt--;
    	        d++;
    	    }
    	    maxcnt = max(maxcnt, cnt);
    	}
    	return maxcnt;
    }
};
