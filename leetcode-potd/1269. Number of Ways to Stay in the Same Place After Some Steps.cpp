You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8
 

Constraints:

1 <= steps <= 500
1 <= arrLen <= 106

class Solution {
    const int MOD = 1000000007;

public:
    int numWays(int steps, int arrLen) {
        vector<unordered_map<int, long long>> vec(steps);
        unordered_map<int, long long> mp, tp;
        mp[0] = 1;
        if(arrLen > 1)
        mp[1] = 1;
        vec[0] = mp;
        for(int i = 1; i < steps; i++){
            mp.clear();
            tp = vec[i-1];
            for(auto it = tp.begin(); it != tp.end(); it++){
                int el = it->first;
                if(el + 1 < arrLen) mp[el+1] = (mp[el+1] + it->second) % MOD;
                if(el - 1 >= 0) mp[el-1] = (mp[el-1] + it->second) % MOD;
                mp[el] = (mp[el] + it->second) % MOD;
            }
            vec[i] = mp;
        }
        return (int)vec[steps - 1][0];
    }
};
