class Solution {
  public:
    void bitManipulation(int num, int i) {
        i = i-1;
        int ithbit = (num&(1<<i)) ? 1:0;
        int setnum = num|(1<<i);
        int clearnum = num&(~(1<<i));
        cout<<ithbit<<" "<<setnum<<" "<<clearnum;
    }
};
