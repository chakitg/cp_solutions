Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105




class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& a) {
        // Code here
        vector<vector<int>> v;
        sort(a.begin(),a.end());
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(v.back()[1] >= a[i][0]) v.back()[1]=max(v.back()[1],a[i][1]);
            else  v.push_back(a[i]);
        }
        return v;
    }
};
