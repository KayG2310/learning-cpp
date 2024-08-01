class Solution {
private:
    vector<int> prev_smaller_equal_element_index(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> next_smaller_element_index(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prev_bigger_element_index(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> next_bigger_element_index(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long s = 0;
        int n = nums.size();
        vector<int> nextsmall = next_smaller_element_index(nums, n);
        vector<int> nextbig = next_bigger_element_index(nums, n);

        vector<int> prevsmall = prev_smaller_equal_element_index(nums, n);
        vector<int> prevbig = prev_bigger_element_index(nums, n);

        for (int i = 0; i < n; i++) {
            long long min_contrib = (long long)(i - prevsmall[i]) * (nextsmall[i] - i) * nums[i];
            long long max_contrib = (long long)(i - prevbig[i]) * (nextbig[i] - i) * nums[i];
            s += max_contrib - min_contrib;
        }

        return s;
    }
};
