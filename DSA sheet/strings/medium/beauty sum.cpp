class Solution {
private:
    int beauty(vector<int>&v){
        int ma = *max_element(v.begin(), v.end());
        int mi = 1e9;
        for(int i=0; i<26; i++){
            if(v[i]>=1){
                mi = min(mi, v[i]);
            }
        }
        return ma-mi;
    }
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0; i<s.length(); i++){
            vector<int>hashmap(26,0);
            for(int j=i; j<s.length(); j++){
                hashmap[s[j]-'a']++;
                sum = sum+ beauty(hashmap);
            }
        }
        return sum;
    }
};
