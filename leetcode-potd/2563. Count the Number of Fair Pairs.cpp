Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109


  class Solution {
public:
    // Prateek
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        // Declare the answer variable  
        long long ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        //sort the array so that we can apply binary search        
        // for every i we have to findits lower and upper
        // since (a,b),(b,a) will be counted as 1 only 
        // we can apply binary seach from i+1 
        for(int i=0;i<n;i++){
            // left and right are the left and right indexes for every i 
            int l=i+1,r=n-1,left=-1,right=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[i]+arr[mid]>=lower){
                    left=mid;
                    r=mid-1;
                }
                else
                l=mid+1;
            }
            l=i+1,r=n-1;
            while(l<=r){
                 int mid=(l+r)/2;
                if(arr[i]+arr[mid]<=upper){
                    right=mid;
                    l=mid+1;
                }
                else
                r=mid-1;
            }
            if(left!=-1&&right!=-1){
            ans+=(right-left+1);}
            
        }
        return ans;
    }
};
