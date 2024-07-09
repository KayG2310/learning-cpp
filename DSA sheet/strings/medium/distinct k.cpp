// for strings
class Solution{
    private:
    long long check(string s, int k){
        if(k==0) return 0;
        unordered_map<char, int> freq;
        long long ans = 0;
        int low = 0, high = 0, n = s.length();
        while (high < n) {
            freq[s[high]]++;
            while (freq.size() > k) {
                freq[s[low]]--;
                if (freq[s[low]] == 0) {
                    freq.erase(s[low]);
                }
                low++;
            }
            // All substrings starting from low and ending at high are valid
            ans+=(high-low+1);
            high++;
        }
        
        return ans;
    }
  public:
    long long int substrCount(string s, int k) {
        return check(s, k)-check(s,k-1);
    }
};

// for vectors
class Solution {
private:
    int check(vector<int>& nums, int k){
        int ans=0;
        unordered_map<int, int> freq;
        int low = 0, high = 0;
        while (high < nums.size()) {
            freq[nums[high]]++;
            while (freq.size() > k) {
                freq[nums[low]]--;
                if (freq[nums[low]] == 0) {
                    freq.erase(nums[low]);
                }
                low++;
            }
            ans+=(high-low+1);
            high++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return check(nums,k)-check(nums,k-1);
    }
};
