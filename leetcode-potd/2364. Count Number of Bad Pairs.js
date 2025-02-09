You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109



/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function(nums) {
    let map = new Map();// we create a map to store the count of non bad pairs
    let count = 0; // stores non bad pair
    let n = nums.length;

   for(let i=0;i<n;i++){
// since  (j - i != nums[j] - nums[i])==(nums[i] - i != nums[j] - j)
        let diff  = nums[i]-i; 
        if(map.has(diff)){// if map already has same diff then its a non bad pair so count the pairs
            count +=map.get(diff);
        }
// increment the current diff to the count if not present make it 1
        map.set(diff,(map.get(diff)||0)+1);
   } 
// we have the count of all non bad pairs
// So we now subtract the all pair with not bad pair
// bad pair = (all possible pair - not bad pair)
   return ((n*(n-1))/2)-count;
};
