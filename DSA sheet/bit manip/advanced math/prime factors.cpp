// brute force
class Solution{
    private:
        bool primecheck(int n){
            // int cnt = 0;
            if(n==1) return false;
            for(int i=2; i<=pow(n,0.5); i++){
                if(n%i==0) return false;
            }
            return true;
        }
	public:
    	vector<int>AllPrimeFactors(int N) {
    	    vector<int>ans;
    	    for(int i=2; i<=N; i++){
    	        if(N%i==0){
    	            if(primecheck(i)) ans.push_back(i);
    	           // if(primecheck(N/i)) ans.push_back(N/i);
    	        }
    	    }
    	    return ans;
    	}
};

// tc = pow(n, 1.5)

// m-2, tc = n if n is large and prime itself
class Solution{
	public:
    	vector<int>AllPrimeFactors(int N) {
    	    vector<int>ans;
    	    for(int i=2; i<=N; i++){
    	        if(N%i==0){
    	            ans.push_back(i);
    	           // if(primecheck(N/i)) ans.push_back(N/i);
    	        }
    	        while(N%i==0){
    	            N = N/i;
    	        }
    	    }
    	    return ans;
    	}
};


// m-3, root n logn
class Solution{
	public:
    	vector<int>AllPrimeFactors(int N) {
    	    vector<int>ans;
    	    for(int i=2; i<=pow(N,0.5); i++){
    	        if(N%i==0){
    	            ans.push_back(i);
    	           // if(primecheck(N/i)) ans.push_back(N/i);
    	        }
    	        while(N%i==0){
    	            N = N/i;
    	        }
    	    }
    	    if(N!=1) ans.push_back(N);
    	    return ans;
    	}
};
