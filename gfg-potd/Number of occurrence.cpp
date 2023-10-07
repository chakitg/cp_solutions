Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
If x is not present in the array (arr) then return 0.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106



class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lower_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            
            if(x <= arr[m])
                r = m;
            else
                l = m + 1;
        }
            
        return l;
    }

    int upper_bound(int arr[], int n, int x) {
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(x >= arr[m])
                l = m + 1;
            else
                r = m;
        }
        
        if(l < n && arr[l] <= x)
            l++;
            
        return l;
    }
    
    int count(int arr[], int n, int x) {
        int start = lower_bound(arr, n, x);
        if(arr[start] != x)
            return 0;
           
        int last = upper_bound(arr, n, x);
        
        return last - start;
    }
};
