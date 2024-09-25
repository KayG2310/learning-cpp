class Solution {
    private:
    int solve(int r){
        if(r%4==0) return r;
        else if(r%4==1) return 1;
        else if(r%4==2) return r+1;
        else return 0;
    }
  public:
    int findXOR(int l, int r) {
        int rxor, lxor;
        rxor = solve(r);
        lxor = solve(l-1);
        return rxor^lxor;
        
        
    }
};
