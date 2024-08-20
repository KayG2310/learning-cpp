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

// better using two pointer, tc = 2n, sc = constant
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlen = 0;
        int l=0, r=0;
        unordered_map<int,int>track;
        
        while(r<arr.size()){
            track[arr[r]]++;
            while(track.size()>2){
                track[arr[l]]--;
                if(track[arr[l]]==0) track.erase(arr[l]);
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
            
        }
        return maxlen;
    }
};

// optimal approach ---> tc = n, sc = constant
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlen = 0;
        int l=0, r=0;
        unordered_map<int,int>track;
        
        while(r<arr.size()){
            track[arr[r]]++;
            if(track.size()>2){
                track[arr[l]]--;
                if(track[arr[l]]==0) track.erase(arr[l]);
                l++;
            }
            if(track.size()<=2)maxlen = max(maxlen, r-l+1);
            r++;
            
        }
        return maxlen;
    }
};
