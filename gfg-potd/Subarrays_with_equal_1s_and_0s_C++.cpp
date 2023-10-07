// Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

// Example 1:

// Input:
// n = 7
// A[] = {1,0,0,1,0,1,1}
// Output: 8
// Explanation: The index range for the 8 
// sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
// (4, 5) ,(2, 5), (0, 5), (1, 6)
// Example 2:

// Input:
// n = 5
// A[] = {1,1,1,1,0}
// Output: 1
// Explanation: The index range for the 
// subarray is (3,4).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countSubarrWithEqualZeroAndOne() which takes the array arr[] and the size of the array as inputs and returns the number of subarrays with equal number of 0s and 1s.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 106
// 0 <= A[i] <= 1

//---------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
      long long int ans = 0 ;
      unordered_map<long long , long long> m ;
      m[0] = 1 ;
      long long s = 0 ;
      for(int i = 0 ; i<n ; i++){
          if(arr[i]==0){
              s -= 1 ;
              ans += m[s] ;
              m[s]++ ;
          }
         else{
              s += 1 ;
              ans += m[s] ;
              m[s]++ ;
         }
      }
      return ans ;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends