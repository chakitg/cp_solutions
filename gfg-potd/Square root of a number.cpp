Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 107







class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        int low = 1, high = n;

        while(low <= high){
            long long mid = (low + high) >> 1;
            long long val = mid * mid;
            if(val <= n){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high;
    }
};
