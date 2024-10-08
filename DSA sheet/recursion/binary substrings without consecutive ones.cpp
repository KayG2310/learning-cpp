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


// iterative - n
class Solution{
public:
	// #define ll long long
	const int mod = 1e9+7;
	ll countStrings(int n) {
	    ll oneend = 1, zeroend = 1;
	    if(n==1) return 2;
	    int i=2;
	    while(i<=n){
	        ll sum = (oneend+zeroend)%mod;
	        oneend = zeroend;
	        zeroend = sum;
	        i++;
	    }
	    return (oneend+zeroend)%mod;
	}
};
