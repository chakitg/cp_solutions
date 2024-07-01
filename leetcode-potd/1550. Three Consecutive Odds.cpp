Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000




#include <bits/stdc++.h>
using namespace std;
#define nline '\n'
#define sp ' '
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
static int fastIO = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
// Paste the Class here-
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2)
            {
                return true;
            }
        }
        return false;
    }
};
