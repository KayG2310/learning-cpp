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

