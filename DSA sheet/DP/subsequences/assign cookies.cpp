// greedy approach already written 
// dp tabulation with space optimisation
class Solution {
public:

    int solve(vector<int>& g,vector<int>& s){
      
        //  vector<vector<int>> dp(g.size()+1,vector<int>(s.size()+1,0));

         vector<int> prev(s.size()+1,0);
         vector<int> curr(s.size()+1,0);
         
         for(int x=g.size()-1;x>=0;x--){
            for(int y=s.size()-1;y>=0;y--){

                
                    if(s[y]>=g[x]){
                        curr[y]=max(prev[y], 1 + prev[y+1]);
                    }
                    else{
                        curr[y]=curr[y+1];
                    }
            }
            prev=curr;
         }

         return prev[0];
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
          sort(g.begin(),g.end());
          sort(s.begin(),s.end());
          return solve(g,s);

        
    }
}; 

// tc = g*s , sc = s 


// explanation
The solution uses a **dynamic programming (DP)** approach to solve the **Assign Cookies** problem. Here’s a detailed explanation of the approach:

---

### **Problem Statement Recap**
You are given two arrays:
1. `g[]` - greed factors of children (minimum size of a cookie a child can be satisfied with).
2. `s[]` - sizes of cookies.

Each child can be assigned only one cookie, and each cookie can only satisfy one child. Your goal is to maximize the number of satisfied children.

---

### **Dynamic Programming Approach**

#### **Core Idea**
- Use **two pointers** (`x` for children and `y` for cookies) with a **2D DP table** where `dp[x][y]` represents the **maximum number of children that can be satisfied** starting from child `x` and cookie `y`.

#### **Optimization: Space Compression**
- Instead of maintaining a full 2D DP table, only maintain two 1D arrays (`prev` and `curr`) for the current and previous rows. This is possible because each `dp[x][y]` depends only on the next row `dp[x+1][...]`.

---

### **Explanation of the Code**

#### 1. **Initialization:**
```cpp
vector<int> prev(s.size()+1, 0);
vector<int> curr(s.size()+1, 0);
```
- `prev`: Stores results for the row `x+1` (next child).
- `curr`: Stores results for the current child `x`.

#### 2. **Iterate Backward Over Children (`x`):**
```cpp
for (int x = g.size() - 1; x >= 0; x--) {
    for (int y = s.size() - 1; y >= 0; y--) {
```
- Iterate backward over children and cookies to build the DP table bottom-up.

#### 3. **Assign Cookie or Skip:**
```cpp
if (s[y] >= g[x]) {
    curr[y] = max(prev[y], 1 + prev[y + 1]);
} else {
    curr[y] = curr[y + 1];
}
```
- **If `s[y] >= g[x]`**: The current cookie can satisfy the current child. 
  - **Case 1:** Skip the child (`prev[y]`).
  - **Case 2:** Assign the cookie (`1 + prev[y+1]`).
  - Take the maximum of these two cases.
- **Else:** The current cookie cannot satisfy the child, so skip the cookie (`curr[y+1]`).

#### 4. **Update for Next Row:**
```cpp
prev = curr;
```
- After processing all cookies for the current child, store the results in `prev` for the next child.

---

### **Returning the Result**
```cpp
return prev[0];
```
- `prev[0]` contains the maximum number of children that can be satisfied starting from the first child and the first cookie.

---

### **Why Sorting?**
```cpp
sort(g.begin(), g.end());
sort(s.begin(), s.end());
```
- Sorting ensures that we process the children with the lowest greed factor and the smallest cookies first, which maximizes the chances of satisfying more children.

---

### **Complexity Analysis**
1. **Time Complexity:**
   - Sorting: \(O(n \log n + m \log m)\), where \(n = \text{size of } g\) and \(m = \text{size of } s\).
   - DP Table: \(O(n \times m)\).
   - Total: \(O(n \log n + m \log m + n \times m)\).

2. **Space Complexity:**
   - Using two 1D arrays of size \(m + 1\): \(O(m)\).

---

### **Example Walkthrough**

#### Input:
```plaintext
g = [1, 2, 3]
s = [1, 1]
```

#### Process:
1. Sort `g` and `s`:
   - `g = [1, 2, 3]`
   - `s = [1, 1]`
2. DP Iterations:
   - For `x = 2 (g[2] = 3)`: No cookies satisfy child.
   - For `x = 1 (g[1] = 2)`: No cookies satisfy child.
   - For `x = 0 (g[0] = 1)`: Cookie `s[0] = 1` satisfies child.

#### Result:
- Maximum children satisfied: `1`.

---

### **Why Use DP?**
This approach ensures that all combinations of children and cookies are considered while minimizing redundant computations through space optimization.
