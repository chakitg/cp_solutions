An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
Example 2:

Input: n = 1
Output: 3
Example 3:

Input: n = 10101
Output: 183236316
 

Constraints:

1 <= n <= 105\





  class Solution {
public:
    int checkRecord(int n) {

        //total status
        //0: 0A 0L
        //1: 0A 1L
        //2: 0A 2L
        //3: 1A 0L
        //4: 1A 1L
        //5: 1A 2L

        long int dp[6] = {1,0,0,0,0,0}; //at 0 day there is 0A0L
        long int tmp[6];
        const long long mod=1e9+7;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<6;j++)tmp[j] = dp[j];

            //NOW STATE-|-------  NEXT STATE ---------|
            //0: 0A 0L => P: 0A0L    A: 1A0L   L: 0A1L
            //1: 0A 1L => P: 0A0L    A: 1A0L   L: 0A2L
            //2: 0A 2L => P: 0A0L    A: 1A0L   L: X
            //3: 1A 0L => P: 1A0L    A: X      L: 1A1L
            //4: 1A 1L => P: 1A0L    A: X      L: 1A2L
            //5: 1A 2L => P: 1A0L    A: X      L: X
            //    every turn
            //0A0L =0+1+2
            //0A1L =0
            //0A2L =1
            //1A0L =0+1+2+3+4+5
            //1A1L =3
            //1A2L =4

            dp[0] =(tmp[0]+tmp[1]+tmp[2])%mod;
            dp[1] =(tmp[0])%mod;
            dp[2] =(tmp[1])%mod;
            dp[3] = (tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] +tmp[5])%mod;
            dp[4] =(tmp[3])%mod;
            dp[5] =(tmp[4])%mod;
        }
        
        return (dp[0]+dp[1]+dp[2]+dp[3]+dp[4]+dp[5])%mod;
        
    }

};
