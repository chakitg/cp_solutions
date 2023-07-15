You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 

Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106




class Solution {
public:

int BS(int index,vector<vector<int>>&events,int value)
{
    int lo = index;
    int hi = events.size()-1;
    int req = -1;
    while(hi>=lo)
    {
      int mid = lo+(hi-lo)/2;
      if(events[mid][0] > value)
      {
        req = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    return req;
}

int helper(int i,vector<vector<int>>&events,int k, vector<vector<int>>&dp)
{
  if(i >= events.size() || k == 0 || i == -1) return 0;
  if(dp[i][k] != -1) return dp[i][k];

  int index = BS(i+1,events,events[i][1]);

  int c1 = events[i][2] + helper(index,events,k-1,dp);
  int c2 = helper(i+1,events,k,dp);

  return dp[i][k] = max(c1,c2);
}


 int maxValue(vector<vector<int>>& events, int k){

    sort(events.begin(),events.end());
    int n = events.size();
    vector<vector<int>>dp(n+5,vector<int>(k+1,-1));
    return helper(0,events,k,dp);
  }
};
