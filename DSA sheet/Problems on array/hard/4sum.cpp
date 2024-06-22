// brute force --> passed 288/294 cases
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> ansdup;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n;k++){
                for(int l= k+1; l<n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum+= nums[l];
                    if(sum==target){
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(), temp.end());
                        ansdup.insert(temp);
                    }
                }
            }
        }
    }
    
    vector<vector<int>>ans(ansdup.begin(), ansdup.end());
    return ans;
    }
};

// better approach ---> not submitted on leetcode
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if(n<4) return {};
    set<vector<int>> ansdup;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long>hashset;
            for(int k=j+1; k<n;k++){
                hashset.insert(nums[k]);
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                int l = target-sum;
                if(hashset.find(l) != hashset.end()){
                    vector<int>temp = {nums[i],nums[j],nums[k], l};
                    sort(temp.begin(), temp.end());
                    ansdup.insert(temp);
                }
            }
        }
    }
    
    vector<vector<int>>ans(ansdup.begin(), ansdup.end());
    return ans;
    }
};

// optimal similar to 3sum problem 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if(n<4) return {};
    int i=0, j=0;
    sort(nums.begin(), nums.end());
    // set<vector<int>> ansdup; no longer needed
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum = nums[i];
                sum+= nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);

                    k++; l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum>target){
                    // we need to decrease sum
                    l--;
                }
                else{
                    k++;
                }


            }
            
            
        }
    }
    return ans;
    }
};
