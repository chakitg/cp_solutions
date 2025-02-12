You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109



/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSum = function (nums) {
    
    const digitSumMap = new Map(), // Map to store the largest number for each digit sum
          length = nums.length;

    /**
     * Function to calculate the sum of digits of a number
     * @param {number} num
     * @return {number}
     */
    const getDigitSum = (num) => {
        let sum = 0;
        const numStr = num.toString(); // Convert number to string for digit extraction
        for (let i = 0; i < numStr.length; i++) {
            sum += parseInt(numStr[i]);
        }
        return sum;
    };
    
    let maxPairSum = -1; // Variable to store the maximum sum of a valid pair
    
    for (let i = 0; i < length; i++) {
        const num = nums[i],
              digitSum = getDigitSum(num),
              existingMaxNum = digitSumMap.get(digitSum); // Get the largest number with the same digit sum

        if (existingMaxNum !== undefined) {
            const currentPairSum = existingMaxNum + num;
            maxPairSum = Math.max(maxPairSum, currentPairSum);
        }
        
        // Update the map with the largest number for the current digit sum
        digitSumMap.set(digitSum, Math.max(existingMaxNum || 0, num));
    }
    
    return maxPairSum;
};
