Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10




class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
    long long mod = 1e9 + 7;
    long long prod = 1;
    vector<int> negatives;
    int countPositives = 0;
    int countZeros = 0;

    if (n == 1) return arr[0] % mod;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            countZeros++;
        } else if (arr[i] < 0) {
            negatives.push_back(arr[i]);
        } else {
            countPositives++;
            prod = (prod * arr[i]) % mod;
        }
    }

    if (countPositives == 0 && negatives.size() == 0) return 0;

    if (countPositives == 0 && countZeros > 0 && negatives.size() == 1) {
        return 0;
    }
    sort(negatives.begin(), negatives.end());

    if (negatives.size() % 2 != 0) {
        for (int i = 0; i < negatives.size() - 1; i++) {
            prod = (prod * negatives[i]) % mod;
        }
    } else {
        for (int i = 0; i < negatives.size(); i++) {
            prod = (prod * negatives[i]) % mod;
        }
    }

    return (prod + mod) % mod;
    }
};
