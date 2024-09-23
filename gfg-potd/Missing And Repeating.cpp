Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n







class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        unordered_map<int, int> mp;
        
        for(int num : arr) {
            mp[num]++;
        }
        
        for (int i = 1; i <= arr.size(); i++) {
            if (mp[i] == 2) {
                ans[0] = i;  // Repeating number
            } else if (mp[i] == 0) {
                ans[1] = i;  // Missing number
            }
        }
        return ans;
    }
};
