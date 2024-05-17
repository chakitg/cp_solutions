Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

Example 1:

Input:
n = 6
x = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output:
1
Explanation:
Pair (2, 80) have absolute difference of 78.
Example 2:

Input:
n = 5
x = 45
arr[] = {90, 70, 20, 80, 50}
Output:
-1
Explanation:
There is no pair with absolute difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes integers n, x, and an array arr[] as input parameters and returns 1 if the required pair exists, return -1 otherwise.

Expected Time Complexity: O(n* Log(n)).
Expected Auxiliary Space: O(1).

Constraints:
1<=n<=106 
1<=arr[i]<=106 
0<=x<=105



  class Solution {

public:

    int findPair(int n, int x, vector<int> &arr) {

        unordered_map<int, int> mp;



        for(auto num: arr) {

            if(mp.count(num - x) or mp.count(x + num))

                return 1;



            mp[num]++;

        }



        return -1;

    }

};
