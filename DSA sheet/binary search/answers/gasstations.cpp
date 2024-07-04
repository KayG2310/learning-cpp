// brute force 
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howmany(n-1,0);
        for(int gasstations=1; gasstations<=k; gasstations++){
            long double maxsection = -1;
            int maxind = -1;
            for(int i=0; i<n-1; i++){
                long double diff = (stations[i+1]-stations[i]);
                long double sectionlength = diff/(howmany[i]+1);
                if(sectionlength>maxsection){
                    maxsection = sectionlength;
                    maxind = i;
                }
            }
            howmany[maxind]++;
        }
        
        long double ans = -1;
        for(int i=0; i<n-1;i++){
            long double diff = (stations[i+1]-stations[i]);
            long double sectionlength = diff/(howmany[i]+1);
            ans = max(ans, sectionlength);
        }
        return ans;
    }
};


// using heaps or priority queues
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howmany(n-1,0);
        priority_queue<pair<long double,int>>pq;
        
        for(int i=0; i<n-1; i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int gas=1; gas<=k; gas++){
            auto tp = pq.top();
            pq.pop();
            int secind = tp.second;
            howmany[secind]++;
            long double initial = tp.first;
            long double final = initial/(long double)(howmany[secind]+1);
            pq.push({final, secind});
            
        }
        
       
        return pq.top().first;
    }
}

// binary search
//in png
int gasstations(vector<int>&arr, long double distance){
	int cnt = 0;
	for(int i=1; i<arr.size(); i++){
		int num = ((arr[i]-arr[i-1])/distance);
		if(arr[i]-arr[i-1] == num*distance){
			num--;
		}
		cnt+=num;

	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for(int i=0; i<n-1;i++){
		high = max(high, (long double)(arr[i+1]-arr[i]));
	}
	long double diff = 1e-6;
	while(high-low>diff){
		long double mid = (high+low)/2.0;
		int cnt = gasstations(arr,mid);
		if(cnt>k){
			low = mid;
			// distance needs to be increased
		}
		else{
			high = mid;
		}

	}	
	return high;
}

