It is a universal fact that Geekina hates 1s however it is also known that Geekina loves the integers having atmost k 1s (set-bits) in their binary representation. 

Geekina demanded nth such non-negative number from Geek, and being a good friend of Geek, now it's your responsibility to tell him that number.

Note: The test cases are generated such that the answer always exists and will fit in the 64-bit data type.

Example 1:

Input:
n = 5
k = 1
Output:
8
Explanation:
Following numbers are loved by Geekina -
0 = (0)2
1 = (1)2
2 = (10)2
4 = (100)2
8 = (1000)2
Example 2:

Input:
n = 6
k = 2
Output:
5
Explanation:
Following numbers are loved by Geekina -
0 = (0)2
1 = (1)2
2 = (10)2
3 = (11)2
4 = (100)2
5 = (101)2
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function findNthNumer() that takes n and k as input parameters. Return the nth number having at most k set-bits.

Expected Time Complexity: O(k*log(n) + constant)
Expected Auxiliary Space: O(k*log(n) + constant)

Constraints:
1 <= n <= 109
1 <= k <= 63




class Solution {
  public:
    long long findNthNumber(long long n, long long k) {
        auto ncr = [](long long n, long long r) -> long long {
            long long ans = 1;
            
            // n! / ((n - r)! * r!)
            
            for(long long i = n; i > max(r, n - r); i--)
                ans *= i;
                
            long long den = 1;
            
            for(long long i = 1; i <= min(r, n - r); i++)
                den *= i;
                
            ans /= den;
            
            return ans;
        };
        
        vector<vector<long long>> dp(63, vector<long long> (k + 1, 0));
        
        for(int i = 0; i < 63; i++){
            for(int j = 0; j < k + 1; j++){
                for(int x = 0; x <= min(i + 1, j); x++)
                    dp[i][j] += ncr(i + 1, x);
            }
        }
        
        long long pos = 0;
        
        for(int i = 0; i < 63; i++){
            if(dp[i][k] >= n){
                pos = i;
                break;
            }
        }
        
        long long ans = 0;
        while(pos > -1 and n > 0){
            if(pos + 1 <= k){
                ans += n - 1;
                break;
            }
            
            if(pos > 0 and dp[pos - 1][k] < n){
                ans |= (1LL << pos);
                n -= dp[pos - 1][k];
                k = max(k - 1, 0LL);
            }
            
            --pos;
        }
        
        return ans;
    }
};
