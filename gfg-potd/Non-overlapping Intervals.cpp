Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
Constraints:
1 ≤ intervals.size() ≤  105
|intervalsi| == 2
0 ≤ starti < endi <=5*104



class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = intervals.size();
        int count = 0;  
        int last_end = INT_MIN;  
        for (const auto& interval : intervals) {
            if (interval[0] >= last_end) {
                last_end = interval[1];  
            } else {
                count++;  
                last_end = min(last_end, interval[1]); 
            }
        }
        return count;
    }
};
