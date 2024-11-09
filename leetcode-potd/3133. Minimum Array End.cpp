You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

 

Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.

 

Constraints:

1 <= n, x <= 108





class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        if (n == 1)
            return ans;
        --n;
        vector<int> ref;
        for (long long i = 0; i < 64; i++) {
            if (!(ans & (1ll << i)))
                ref.push_back(i);
        }
        for (int i = 0; n; i++, n >>= 1) {
            ans += (n & 1ll) << ref[i];
        }

        return ans;
    }
};
