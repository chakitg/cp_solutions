Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104






class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    long ans = 0;
    // prevMin[i] := index k s.t. arr[k] is the previous minimum in arr[:i]
    vector<int> prevMin(n, -1);
    // nextMin[i] := index k s.t. arr[k] is the next minimum in arr[i + 1:]
    vector<int> nextMin(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && arr[stack.top()] > arr[i]) {
        const int index = stack.top();
        stack.pop();
        nextMin[index] = i;
      }
      if (!stack.empty())
        prevMin[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      ans += static_cast<long>(arr[i]) * (i - prevMin[i]) * (nextMin[i] - i);
      ans %= kMod;
    }

    return ans;
  }
};
