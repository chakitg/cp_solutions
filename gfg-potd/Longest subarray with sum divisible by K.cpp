Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 
4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
Example 2:

Input:
N = 7, K = 3
arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output: 
5
Explanation:
The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
Your Task:
The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= K <= 109
-109 <= A[i] <= 109 





class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int out = 0, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int rem = sum % k;
            
            if (rem < 0)
                rem += k;
            
            if (mp.find(rem) != mp.end())
                out = max(out, i - mp[rem]);
            else
                mp[rem] = i;
        }
        
        return out;
    }
};
