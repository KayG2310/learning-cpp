// brute force solution
class Solution{
public:
	int rowWithMax1s(vector<vector<int> >&arr, int n, int m) {
	    map<int, vector<int>> m2;
	    for(int i=0; i<n;i++){
	        int cnt = 0;
	        for(int j=0; j<m; j++){
	            cnt+=arr[i][j];
	        }
	        m2[-1*cnt].push_back(i);
	    }
	    auto it = m2.begin();
	    vector<int>v = (*it).second;
	    if((*it).first !=0) return *min_element(v.begin(), v.end());
	    return -1;
	}

};
/*
0 0
0 0 

1st row cnt = 3,

*/

class Solution{
public:
	int rowWithMax1s(vector<vector<int> >&arr, int n, int m) {
	    int cntmax = 0;
	    int index = -1;
	    for(int i=0; i<n;i++){
	        int cntones = m - (lower_bound(arr[i].begin(), arr[i].end(),1)-arr[i].begin());
	        if(cntones>cntmax){
	            index = i;
	            cntmax = cntones;
	        }
	    }
	    return index;
	}

};
