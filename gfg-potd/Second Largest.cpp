Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105




class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr)
    {
        int n=arr.size();
        if (n<2)
            return -1;
        int max_=INT_MIN;
        int sec_max=INT_MIN;
        for (int i=0;i<n;i++)
        {
            if (arr[i]>max_)
            {
                sec_max=max_;
                max_=arr[i];
            }
            else if (arr[i]>sec_max && arr[i]!=max_)
                sec_max=arr[i];
        }
        if (max_==sec_max || sec_max==INT_MIN)
            return -1;
        else return sec_max;
    }
};
