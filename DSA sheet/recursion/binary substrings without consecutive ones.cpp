// potentially recursive approach 
class Solution{
public:
	// #define ll long long
	const int mod = 1e9+7;
	
	ll foo(ll zeroend, ll oneend, int n, int i){
	    ll sum=zeroend+oneend;
	    if(i==1) return sum%mod;
	    return foo(sum, zeroend, n, i-1)%mod;
	}
	ll countStrings(int n) {
	    return foo(1,1,n,n)%mod;
	}
};

// it works with iterative approach much better
// recursive 2 ---> method in copy
