You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
num1 = 1033 
num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach num2 from num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
num1 = 1033 
num2 = 1033
Output:
0
Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers num1 and num2 as input parameters and returns the distance of the shortest path from num1 to num2. If it is unreachable then return -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1000<=num1,num2<=9999
num1 and num2 are prime numbers.







class Solution {
public:
    vector<bool> isPrime;

    void seive() {
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i < isPrime.size(); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }
    }

    int solve(int Num1, int Num2) {
        isPrime = vector<bool>(10000, true);
        seive();

        string tar = to_string(Num2);

        unordered_set<string> vis;
        queue<string> q;
        q.push(to_string(Num1));
        vis.insert(to_string(Num1));
        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front(), perm;
                q.pop();

                if (curr == tar)
                    return lvl;

                for (int i = 0; i < 4; ++i) {
                    perm = curr;
                    for (char c = '0'; c <= '9'; ++c) {
                        if (i == 0 && c == '0')
                            continue;

                        perm[i] = c;
                        if (isPrime[stoi(perm)] && vis.find(perm) == vis.end()) {
                            vis.insert(perm);
                            q.push(perm);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
