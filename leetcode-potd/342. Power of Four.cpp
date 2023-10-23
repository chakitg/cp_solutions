Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1



class Solution {
public:
    bool isPowerOfFour(int n) {
        int low = 0;
        int high = 1e9;
        while(low<=high){
            int mid = (low+high)>>1;
            if(pow(4,mid)==n) return true;
            else if(pow(4,mid)>n) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
