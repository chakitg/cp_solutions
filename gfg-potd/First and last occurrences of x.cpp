Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.


Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i],x ≤ 109




class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        if(x<arr[0] || x>arr[n-1])
            return {-1, -1};
        int st=0, en=n-1;
        int lo = 0, hi = n-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == x){
                if((mid-1)>0 && arr[mid-1]!=x){
                    st = mid;
                    break;
                }
                else if(mid==0){
                    st = mid;
                    break;
                }
                else{
                    hi = mid-1;
                }
            }
            else if(arr[mid] > x){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        if(arr[st]!=x)
            return {-1, -1};
        
        lo = st, hi = n-1;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == x){
                if((mid+1)<n && arr[mid+1]!=x){
                    en = mid;
                    break;
                }
                else if(mid==n-1){
                    en = mid;
                    break;
                }
                else{
                    lo = mid+1;
                }
            }
            else if(arr[mid] > x){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return {st, en};
    }
};
