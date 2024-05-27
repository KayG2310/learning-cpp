#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int count = 0;
    while (x > 0 || y > 0) {
        int bit_x = x & 1;
        int bit_y = y & 1;

        if (bit_x != bit_y)count++;
        
        x = x >> 1;
        y = y >> 1;
    }
    return count;
}

int totalHammingDistance(vector<int> nums) {
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            sum += hammingDistance(nums[i], nums[j]);
        }
        
    }
    return sum;
}

can give tle

// another approach by gpt
class Solution {
public:


    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int totalDistance = 0;
        
        // Iterate through each bit position
        for (int bit = 0; bit < 32; ++bit) {
            int setBits = 0;
            
            // Count the number of set bits at the current bit position
            for (int num : nums) {
                if (num & (1 << bit)) {
                    setBits++;
                }
            }
            
            // Total Hamming distance at the current bit position
            int unsetBits = n - setBits;
            totalDistance += setBits * unsetBits;
        }
        
        return totalDistance;
    }
};
