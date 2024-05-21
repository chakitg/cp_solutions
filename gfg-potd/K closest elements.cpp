Given a sorted array of unique elements in increasing order, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.
 
Example 1:

Input:
n = 13
arr[] = {12, 16, 22, 30, 35, 39, 42, 
         45, 48, 50, 53, 55, 56}
k = 4, x = 35
Output: 39 30 42 45
Explanation: 
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.

Example 2:

Input:
n = 5
arr[] = {1, 2, 3, 6, 10}
k = 3, x = 4
Output: 3 6 2
Explanation: 
First closest element is 3.
There are two elements 2 and 6 for which 
the difference with 4 is same i.e. 2.
So first take greatest number 6 
then the lower number 2.

Your Task:
You don't need to read input or print anything. Complete the function printKClosest() which takes arr[], n, k, and x as input parameters and returns an array of integers containing the K closest elements to x in arr[].


Expected Time Complexity: O(log n + k)
Expected Auxiliary Space: O(k)


Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ n
1 ≤ x ≤ 106
1 ≤ arr[i] ≤ 106






class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        map<int,vector<int>> mp;
        for(auto it:arr){
            mp[abs(it-x)].push_back(it);
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.first==0){
                continue;
            }
            if(k==0){
                break;
            }
            sort(it.second.rbegin(),it.second.rend());
            for(auto num:it.second){
                ans.push_back(num);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        return ans;
    }
};
