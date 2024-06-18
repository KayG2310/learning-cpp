// leetcode submission
int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size();i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size();
    }

// brute force (searching for element inside the given range O(N2), sc = O(1)

// better - using hashing
int n = 5;
    int arr[4] = {1,2,4,5};
    int hash[n+1] = {0};
    for(int i=1; i<=n; i++){
        if(arr[i-1]==i){
            hash[i] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        if (hash[i]==0){
            cout<<i;
            break;
        }
    }

// optimal approach
int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int sum2 = accumulate(nums.begin(), nums.end(),0);
        return sum-sum2;
    }

// approach 2 XOR
int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for(int i=1; i<=n; i++){
            xor1 = xor1 ^ i;
        }
        for(int i=0; i<n; i++){
            xor2 = xor2 ^ nums[i];
        }
        return xor1 ^ xor2;
    }
