Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.



/**************************\U0001f60e**************************/
const sortColors = (nums) => {
     let red = 0
     let white = 0
     let blue = nums.length -1

     while(white <= blue){
        if(nums[white] === 0){
          [nums[red], nums[white]] = [nums[white], nums[red]]
          red++
          white++
        }else if(nums[white] === 1){
          white++
        }
        else if(nums[white] === 2){
         [nums[white], nums[blue]] = [nums[blue] ,nums[white]]
         blue--
        }

     }
};
