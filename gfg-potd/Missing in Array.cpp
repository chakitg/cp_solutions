Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive), find the missing element. The array is a permutation of size n with one element missing. Return the missing element.

Examples:

Input: n = 5, arr[] = [1,2,3,5]
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.
Input: n = 2, arr[] = [1]
Output: 2
Explanation : All the numbers from 1 to 2 are present except 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ n




class Solution {
  private:
    int approach_1(int n, vector<int>& arr) {
        sort(begin(arr), end(arr));
        for (int i = 0; i < n; i ++) {
            if (i + 1 != arr[i]) {
                return (i + 1);
            }
        }
        return n;
    }

    int approach_2(int n, vector<int>& arr) {
        int wholeSum = (n * (n + 1)) / 2;
        int totalSum = accumulate(begin(arr), end(arr), 0);
        return wholeSum - totalSum;
    }

    int approach_3(int n, vector<int>& arr) {
        int xor_all = 0;
        for (int i = 0; i < arr.size(); i ++) {
            xor_all ^= arr[i];
        }
        for (int i = 1; i <= n; i ++) {
            xor_all ^= i;
        }
        return xor_all;
    }
  public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        // return approach_1(n, arr);

        // return approach_2(n, arr);

        return approach_3(n, arr);
    }
};
