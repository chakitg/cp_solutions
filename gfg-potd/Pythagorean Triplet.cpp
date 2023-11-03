
Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.
Your Task:
You don't have to take any input or print any thing. You have to complete the function checkTriplet() which takes an array arr, a single integer n, as input parameters and returns boolean denoting answer to the problem.
Note: The driver will print "Yes" or "No" instead of corresponding to the boolean value returned.

Expected Time Complexity: O(n+max(Arr[i])2)
Expected Auxiliary Space: O(max(Arr[i]))

Constraints:
1 <= n <= 105
1 <= arr[i] <= 1000





class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) 
	{
	    // code here
	    int a[n];
	    for(int i=0;i<n;i++)
	    a[i]=pow(arr[i],2);
	    
	    unordered_map<int,bool>mp;
	    for(int i=0;i<n;i++)
	    mp[a[i]]=true;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            int sum=a[i]+a[j];
	            if(mp[sum]==true)
	            return true;
	        }
	    }
	    return false;
	}
};
