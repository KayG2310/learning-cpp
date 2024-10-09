// tc = 2^n

// return count
class Solution{
	public:
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n, int &cnt){
    if(ind == n) {
        if(s == sum) {
            cnt++;
        }
        return;
    }

    // pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind+1, ds, s, sum, arr, n, cnt);

    // backtrack: remove the element
    s -= arr[ind];
    ds.pop_back();

    // not pick the element
    printS(ind+1, ds, s, sum, arr, n, cnt);
}

	int perfectSum(int arr[], int n, int sum)
	{
        vector<int>ds;
        int cnt = 0;
        printS(0, ds, 0, sum, arr, n, cnt);
        return cnt;
	}
	  
};

// modified 
// check if exists
class Solution{
	public:
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n, int &cnt){
    if(ind == n) {
        if(s == sum) {
            return true;
        }
        return false;
    }

    // pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    if(printS(ind+1, ds, s, sum, arr, n, cnt)== true) return true;

    // backtrack: remove the element
    s -= arr[ind];
    ds.pop_back();

    // not pick the element
    if(printS(ind+1, ds, s, sum, arr, n, cnt)==true) return true;
  return false;
}

	int perfectSum(int arr[], int n, int sum)
	{
        vector<int>ds;
        int cnt = 0;
        return printS(0, ds, 0, sum, arr, n, cnt);
        // return cnt;
	}
	  
};

class Solution{

	public:
int printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind == n) {
        if(s == sum) {
            // cnt++;
            return 1;
        }
        return 0;
    }

    // pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    int x= printS(ind+1, ds, s, sum, arr, n);

    // backtrack: remove the element
    s -= arr[ind];
    ds.pop_back();

    // not pick the element
    int y = printS(ind+1, ds, s, sum, arr, n);
    return x+y;
}

	int perfectSum(int arr[], int n, int sum)
	{
        vector<int>ds;
        // int cnt = 0;
        return printS(0, ds, 0, sum, arr, n);
        // return cnt;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
