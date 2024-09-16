Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".




  class Solution {
public:
    
    int get_minutes(string time_point) {
        return ((((time_point[0] - '0') * 10) + (time_point[1] - '0')) * 60) + (((time_point[3] - '0') * 10) + (time_point[4] - '0'));
    }

    int findMinDifference(vector<string>& time_points) {
        vector<int> minutes;

        for (auto m : time_points) {
            minutes.push_back(get_minutes(m));
        }
    
        sort(minutes.begin(), minutes.end());
    
        int min_diff = INT_MAX;
    
        for (int i = 1; i < minutes.size(); i++) {
            min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
        }

        return min(min_diff, abs(minutes[0] + 1440 - minutes[minutes.size() - 1]));
    }
};
