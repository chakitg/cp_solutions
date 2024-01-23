There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 

Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases. One possible order is [0, 1].
Example 2:

Input:
n = 4, m = 4
prerequisites = {{1, 0},
               {2, 0},
               {3, 1},
               {3, 2}}
Output:
1
Explanation:
There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of 1.
Your Task:
The task is to complete the function findOrder() which takes two integers n, and m and a list of lists of size m*2 denoting the prerequisite pairs as input and returns any correct order to finish all the tasks. Return an empty array if it's impossible to finish all tasks.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).
 
Constraints:
1 ≤ n ≤ 105
0 ≤ m ≤ min(n*(n-1),105)
0 ≤ prerequisites[i][0], prerequisites[i][1] < n
All prerequisite pairs are unique
prerequisites[i][0] ≠ prerequisites[i][1]




class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
        vector<int> graph[n];
        vector<int> degree(n, 0);

        for (auto i : pre) {
            degree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (!degree[i])
                q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for (auto i : graph[front]) {
                degree[i]--;
                if (degree[i] == 0)
                    q.push(i);
            }
        }

        for (auto i : degree) {
            if (i >= 1)
                return {};
        }

        return ans;
    }
};
