Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length






class Solution {
public:
    // time/space: O(nlogn)/O(n)
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // count the frequency for each integer
        unordered_map<int, int> freq;
        for (auto& num : arr) freq[num]++;

        // put {frequency, integer} into a priority queue, and keep the least frequency on the top
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto& [num, f] : freq) pq.push({f, num});

        // remove exactly `k` elements
        while (k > 0) {
            auto& top = pq.top();
            int f = top[0], num = top[1];
            pq.pop();

            if (k >= f) {
                k -= f;
            }
            else {
                k = 0;
                pq.push({f - k, num});
            }
        }

        return pq.size();
    }
};
