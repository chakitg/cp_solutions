Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

Example 1:


Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.






class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> points;
        points.insert("0,0");
        int x = 0, y = 0;

        for (char d : path) {
            if (d == 'N') y++;
            else if (d == 'S') y--;
            else if (d == 'E') x++;
            else if (d == 'W') x--;

            if (points.count(to_string(x) + "," + to_string(y))) return true;
            points.insert(to_string(x) + "," + to_string(y));
        }

        return false;        
    }
};
