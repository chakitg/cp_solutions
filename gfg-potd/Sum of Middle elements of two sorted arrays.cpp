Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr1.size() == arr2.size() <= 103
1 <= arr1[i] <= 106
1 <= arr2[i] <= 106






class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        int n1 = (n + m) / 2;
        int low = 0;
        int high = n;
        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int l1 = mid1 > 0 ? arr1[mid1 - 1] : INT_MIN;
            int mid2 = n1 - mid1;
            int l2 = mid2 > 0 ? arr2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n ? arr1[mid1] : INT_MAX;
            int r2 = mid2 < m ? arr2[mid2] : INT_MAX;
            if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else if (l2 > r1)
            {
                low = mid1 + 1;
            }
            else
            {
                return max(l1, l2) + min(r1, r2);
            }
        }
        return -1;
    }
};
