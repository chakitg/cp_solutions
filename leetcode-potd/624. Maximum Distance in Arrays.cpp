You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.







class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min_num = arrays[0].front();
        int max_num = arrays[0].back();
        int max_dis = INT_MIN;

        for(int i=1; i<n; i++)
        {
            max_dis = max({max_dis, abs(arrays[i].back() - min_num), abs(arrays[i].front() - max_num)});
            min_num = min(min_num, arrays[i].front());
            max_num = max(max_num, arrays[i].back());
        }

        return max_dis;
    }
};
