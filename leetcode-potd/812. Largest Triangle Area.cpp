// Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:


// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
// Output: 2.00000
// Explanation: The five points are shown in the above figure. The red triangle is the largest.
// Example 2:

// Input: points = [[1,0],[0,0],[0,1]]
// Output: 0.50000
 

// Constraints:

// 3 <= points.length <= 50
// -50 <= xi, yi <= 50
// All the given points are unique.







class Solution {
public:
    using Point = std::vector<int32_t>;

    double triangleArea(Point const& p0, Point const& p1, Point const& p2) {
        return 0.5 * std::abs((p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1]));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double result = 0.0;
        for(int32_t i = 0; i < points.size(); i++) {
            for(int32_t j = i + 1; j < points.size(); j++) {
                for(int32_t k = j + 1; k < points.size(); k++) {
                    double area = triangleArea(points[i], points[j], points[k]);
                    result = std::max(result, area);
                }
            }
        }
        return result;
    }
};
