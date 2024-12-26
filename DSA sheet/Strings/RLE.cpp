class Solution {
public:
    string countAndSay(int n) {
        string rle = "1";
        if(n==1) return rle;
        for (int ii = 2; ii <= n; ii++) {
            string nrle = "";
            int cnt = 1; 
            for (int i = 1; i < rle.length(); i++) {
                if (rle[i] == rle[i - 1]) {
                    cnt++;
                } 
                else {
                    nrle += to_string(cnt) + rle[i - 1]; 
                    cnt = 1; 
                }
            }
            nrle += to_string(cnt) + rle.back();
            rle = nrle;
        }
        return rle;
    }
};
