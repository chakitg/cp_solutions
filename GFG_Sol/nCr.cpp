// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

// Example 1:

// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3. 
// Example 2:

// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.
// Your Task:
// You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..

// Expected Time Complexity: O(n*r)
// Expected Auxiliary Space: O(r)

// Constraints:
// 1 ≤ n ≤ 1000
// 1 ≤ r ≤ 800


class Solution{
public:
    int M = 1e9 +7;
    int binpow(int a, int b, int m) {
        int res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * 1LL * a) % m;
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return res;
    }

    int mmi(int a, int m) {
        return binpow(a, m-2, m);
    }
    
    int nCr(int n, int r){
        if (n < r) return 0;
        r = min(n-r, r);
        
        int num = 1, deno = 1;
        for (int i = 1; i <= r; ++i) {
            num = (num * 1LL * (n-i+1)) % M;
            deno = (deno * 1LL * i) % M;
        } 
        
        return (num * 1LL * mmi(deno, M)) % M;

    }
};
