You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.




class Solution {
public:
    vector<int> possible(vector<set<int>>& ranges, int mid) {
        int n = ranges.size();
        
        int pivot = -1e5;

        while(true) {
            int next = 1e5, maxi = pivot;

            for(int i=0; i<n; i++) {
                auto it = ranges[i].lower_bound(pivot);
                auto ub = ranges[i].upper_bound(pivot);
               
                if(it == ranges[i].end())
                    return { 0, -1 };

                if(ub != ranges[i].end())
                    next = min(next, *ub);

                maxi = max(maxi, *it);
            }

            if(maxi - pivot <= mid)
                return { pivot, maxi };
            
            pivot = next;
        }

        return { 0, -1 };
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<set<int>> ranges(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<nums[i].size(); j++) {
                ranges[i].insert(nums[i][j]);
            }
        }

        vector<int> ans;

        int lo = 0, hi = 1e7;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;

            vector<int> tmp = possible(ranges, mid);
            if(tmp[1] >= tmp[0]) {
                ans = tmp;
                hi = mid - 1;
            }

            else
                lo = mid + 1;
        }

        return ans;
    }
};
