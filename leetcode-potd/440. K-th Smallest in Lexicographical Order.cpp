Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109





class Solution {
private:
// helper(13, 1, 2)
// steps = 2 - 1    --> 1
// 10,  20
// steps = 14 - 10
// steps = 4 + 1    --> 5
    int helper(int n, long prefix1, long prefix2){
        int steps = 0;
        while(prefix1 <= n){
            steps += min((long) n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // We were given two integers n and k. We need to return the kth smallest Lexicographically ordered integer in the range [1, n].
        // At the very beginning or the inital glance to solve this problem would be that we need to generate all the numbers from 1 to n and then Lexiographically sort them and check the possibility.
        // 10 ^ 9
        // O(n log n) --> 10 ^ 9
        // 10 ^ 5 -- O(n)
        // 10 ^ 9
        // Every number as a separate node in itself
        // 1        2           3           4           5           6
        // 10   11
        // 100  110
        // 1000
        // 10000
        int curr = 1;
        k--;
        
        // n = 13
        // k = 2
        // We need to find the second smallest lexicographical number
        
        // 1        2           3           4           5       6
        // helper(13, 1, 2) k = 1

        while(k > 0){
            int steps = helper(n, curr, curr + 1);
            if(steps <= k){
                curr++;
                k -= steps;
            }
            else{
                curr *= 10;
                k--;
            }
        }

        return curr;

    }
};
