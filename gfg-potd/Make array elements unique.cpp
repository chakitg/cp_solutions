Given an array arr[ ], your task is to find the minimum number of increment operations required to make all the elements of the array unique. i.e.- no value in the array should occur more than once. In one operation, a value can be incremented by 1 only.

Examples :

Input: arr[] = [1, 2, 2]
Output: 1
Explanation: If we increase arr[2] by 1 then the resulting array becomes {1, 2, 3} and has all unique values.Hence, the answer is 1 in this case.
Input: arr[] = [1, 1, 2, 3]
Output: 3
Explanation: If we increase arr[0] by 3, then all array elements will be unique. Hence, the answer is 3 in this case.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 0
Explanation: All elements are unique.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106




class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = 0;
        for(int i=1; i<n; i++){
            if(arr[i]<=arr[i-1]){
                int diff= arr[i-1]-arr[i]+1;
                res+= diff;
                arr[i]+= diff;
            }
        }
        return res;
        
    }
};
