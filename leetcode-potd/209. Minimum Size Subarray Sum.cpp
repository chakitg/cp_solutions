// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).











Sliding Window Approach
Initialize two pointers, i and j, to track the start and end of the current subarray, respectively. Set i and j to 0 initially.
Initialize a variable sum to keep track of the current sum of elements in the subarray.
Initialize a variable mn to store the minimum length found so far. Set it to the maximum possible integer value (INT_MAX).
Start a while loop that continues until the j pointer reaches the end of the array nums.
Inside the loop, add the element at index j to the sum variable.
Check if the sum is greater than or equal to the target value.
If the condition is true, enter another while loop. This loop will handle the case where the current subarray sum is equal to or greater than the target.
a. Decrement the sum by subtracting the element at index i.
b. Update mn with the minimum length found so far (j - i + 1).
c. Increment the i pointer to move the window to the right.
d. Repeat steps a-c until the sum is no longer greater than or equal to the target value.
Increment the j pointer to move the window to the right.
Repeat steps 5-8 until the j pointer reaches the end of the array.
After the loop, check if the value of mn is still INT_MAX, indicating that no subarray was found. In this case, return 0.
Otherwise, return the value of mn, which represents the minimum length of a subarray whose sum is greater than or equal to the target.
The sliding window technique allows us to efficiently search for the minimum length subarray that satisfies the given condition. By maintaining two pointers and adjusting the window based on the sum of elements, we can avoid unnecessary computations and achieve a time complexity of O(N), where N is the size of the input array nums.

Code1 Sliding Window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int mn=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                mn=min(j-i+1,mn);
                i++;
            }
            j++;
        }
        if(mn==INT_MAX){
            return 0;
        }
        return mn;
    }
};
Complexity
Time complexity: O(n)O(n)O(n)
Space complexity: O(1)

  
  
  
  
  
Code2 Binary Search
Binary Search Approach
The windowfind function checks if there exists a subarray of a given size whose sum is greater than or equal to the target.
It uses the sliding window technique to iterate through the array and maintain a window of the specified size.
If the sum of the elements in the window is greater than or equal to the target, it returns true.
Otherwise, it returns false.
The minSubArrayLen function finds the minimum length of a subarray whose sum is greater than or equal to the target using binary search.

It initializes a range from 1 to the size of the input array.
It repeatedly divides the range in half and checks if a subarray of the mid-point length satisfies the condition using the windowfind function.
If a valid subarray is found, it updates the upper bound of the range to mid-1 and stores the mid-point length as the minimum length found so far.
If a valid subarray is not found, it updates the lower bound of the range to mid+1.
The search continues until the lower bound is no longer less than or equal to the upper bound.
Finally, it returns the minimum length of the subarray.
The code efficiently utilizes the sliding window technique and binary search to find the minimum length subarray satisfying the given condition.

class Solution {
public:
      bool windowfind(int size, vector<int>&nums, int target) {
        int sum = 0;
        int i=0;
        int j=0;
        int mx=INT_MIN;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            if(j-i+1==size){
              mx=max(sum,mx);
              sum-=nums[i];
              i++;
            }
            j++;
        }
        if(mx>=target)
        return true;
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1, high = nums.size(), mn = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (windowfind(mid, nums, target)) {
                high = mid-1;
                mn = mid;
            } else low = mid + 1;
        }
        return mn;
    }
};
Complexity
Time complexity: O(nlogn)O(n logn)O(nlogn)
Space complexity: O(1)
