class Solution {
  public:
  set<string> subsets(string &s) {
        int n = s.length();
        set<string>sett;
        for(int i=0; i<(1<<n); i++){
            string sub = "";
            int j=i, c=0;
            while(j){
                if((j&1) != 0){
                    sub += s[n-1-c];
                }
                j=j>>1;
                c++;
            }
            sett.insert(sub);
        }
        return sett;
    }
    string betterString(string str1, string str2) {
        set<string>s1 = subsets(str1);
        set<string>s2 = subsets(str2);
        
        if(s1.size()>= s2.size()) return str1;
        return str2;
    }
};

// tc = 2^n log n
