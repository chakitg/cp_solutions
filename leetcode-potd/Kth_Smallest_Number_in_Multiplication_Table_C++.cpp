// Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

// Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

 

// Example 1:


// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.
// Example 2:


// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6.
 

// Constraints:

// 1 <= m, n <= 3 * 104
// 1 <= k <= m * n


class Solution {
public:
    int findKthNumber(int m, int n, int k) {
       int low = 1, high = m * n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = getLowerNum(m, n, mid);
            if(count < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    private:
    int getLowerNum(int m, int n, int target){
        int row = m - 1, col = 0;
        int res = 0;
        while(row >= 0 && col < n){
            if((row + 1) * (col + 1) > target) row--;
            else{
                res += row + 1;
                col++;
            }
        }
        return res;
        
    }
};