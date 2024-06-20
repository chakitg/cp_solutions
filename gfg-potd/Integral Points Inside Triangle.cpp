Given three non-collinear points whose co-ordinates are p(p1, p2), q(q1, q2) and r(r1, r2) in the X-Y plane. Return the number of integral / lattice points strictly inside the triangle formed by these points.
Note: - A point in the X-Y plane is said to be an integral / lattice point if both its coordinates are integral.

Examples

Input: p = (0,0), q = (0,5), r = (5,0)
Output: 6
Explanation: 

As shown in figure, points (1,1) (1,2) (1,3) (2,1) (2,2) and (3,1) are the integral points inside the triangle. So total 6 are there.
Input: p = (62,-3), q = (5,-45), r = (-19,-23)
Output: 1129
Explanation: There are 1129 integral points in the triangle formed by p, q and r.
Expected Time Complexity: O(Log2109)
Expected Auxillary Space: O(1)

Constraints:
-109 ≤ x-coordinate, y-coordinate ≤ 109




class Solution {
  public:
  long long gcd(long long a, long long b) {
    //   code here
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long InternalCount(long long p[], long long q[], long long r[]) {
        // Calculate the area of the triangle using the determinant method
        long long area = 0;
        area += (p[0] * q[1]) - (p[1] * q[0]);
        area += (q[0] * r[1]) - (q[1] * r[0]);
        area += (r[0] * p[1]) - (r[1] * p[0]);

        // Calculate the number of boundary points using gcd
        long long boundaryPoints = 0;
        boundaryPoints += gcd(abs(p[0] - q[0]), abs(p[1] - q[1]));
        boundaryPoints += gcd(abs(r[0] - q[0]), abs(r[1] - q[1]));
        boundaryPoints += gcd(abs(p[0] - r[0]), abs(p[1] - r[1]));

        // Use Pick's Theorem to find the number of interior points
        return abs(area) / 2 - boundaryPoints / 2 + 1;
    }
};
