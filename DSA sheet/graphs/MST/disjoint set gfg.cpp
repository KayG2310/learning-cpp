int find(int A[],int X)
{
       //add code here
       if(A[X]==X) return X;
       return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	int pz = find(A, Z);
	int px = find(A, X);
	if(pz != px){
	    // ultimate parents are not same
	    A[px] = pz; 
	}

}
