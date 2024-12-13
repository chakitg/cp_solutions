A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109



class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        // Perform binary search
        while (low < high) {
            int mid = (low + high) / 2;
            // Check which part contains the minimum
            if (arr[mid] <= arr[high]) {
                high = mid; // Minimum is in the left part (or mid itself)
            } else {
                low = mid + 1; // Minimum is in the right part
            }
        }
        // Return the minimum element
        return arr[low];
    }
};
