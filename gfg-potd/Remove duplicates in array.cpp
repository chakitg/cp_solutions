Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]
Constraints:
1<= arr.size() <=106
2<= arr[i] <=100


  class Solution {
  public:
    vector<int> removeDuplicate(vector<int> &arr) {
        int res_ind = 1;
        for (int i = 1; i < arr.size(); i++) {
            int j;
            for (j = 0; j < i; j++)
                if (arr[i] == arr[j])
                    break;
            if (j == i)
                arr[res_ind++] = arr[i];
        }
        arr.erase(arr.begin() + res_ind, arr.end());
        return arr; 
    }
};
