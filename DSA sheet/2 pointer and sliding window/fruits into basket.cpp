// brute force tc = n2* log3, sc = o(2)
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlen = 0;
        
        for(int i = 0; i<arr.size(); i++){
            set<int>fruits;
            fruits.insert(arr[i]);
            for(int j = i; j<arr.size(); j++){
                fruits.insert(arr[j]);
                if(fruits.size()<=2){
                    maxlen = max(maxlen, j-i+1);
                }
                else{
                    break;
                }
            }
            
        }
        return maxlen;
    }
};
