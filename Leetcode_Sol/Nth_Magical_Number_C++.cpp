// A positive integer is magical if it is divisible by either a or b.

// Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 1, a = 2, b = 3
// Output: 2
// Example 2:

// Input: n = 4, a = 2, b = 3
// Output: 6
// Example 3:

// Input: n = 5, a = 2, b = 4
// Output: 10
// Example 4:

// Input: n = 3, a = 6, b = 4
// Output: 8
 

// Constraints:

// 1 <= n <= 109
// 2 <= a, b <= 4 * 104

//-------------------------------------------------------------------------------------------------------------



typedef long long int lli;
const lli MOD = 1e9 + 7;
class Solution {
public:
    int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
   int lcm(int a, int b) { return (a * b) / gcd(a, b); }
   lli cnt(lli x, lli A, lli B) {
      return (x / A) + (x / B) - (x / lcm(A, B));
   }
   int nthMagicalNumber(int N, int A, int B) {
      lli l = 2;
      lli r = 1e14;
      lli ret = 0;
      while (l <= r) {
         lli mid = l + (r - l) / 2;
         lli k = cnt(mid, A, B);
         if (k < N) {
            l = mid + 1;
         } else {
            ret = mid;
            r = mid - 1;
         }
      }
      ret %= MOD;
      return ret;
        
    }
};