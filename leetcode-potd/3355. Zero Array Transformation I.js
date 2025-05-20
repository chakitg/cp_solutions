You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

 

Example 1:

Input: nums = [1,0,1], queries = [[0,2]]

Output: true

Explanation:

For i = 0:
Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
The array will become [0, 0, 0], which is a Zero Array.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

Output: false

Explanation:

For i = 0:
Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
The array will become [4, 2, 1, 0].
For i = 1:
Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
The array will become [3, 1, 0, 0], which is not a Zero Array.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length




/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean}
 */
function isZeroArray(nums, queries) {
  const arrayLength = nums.length;

  // Use a typed Int32Array to get native fast increments/decrements
  const differenceArray = new Int32Array(arrayLength + 1);

  // Cache queries.length and avoid array-destructuring and boundary checks
  const queryCount = queries.length;
  for (let i = 0; i < queryCount; ++i) {
    const currentQuery = queries[i];
    
    // The currentQuery[0] ∈ [0..arrayLength-1], so currentQuery[1]+1 ∈ [1..arrayLength]
    differenceArray[currentQuery[0]] += 1;
    differenceArray[currentQuery[1] + 1] -= 1;
  }

  // Accumulate in place and check on the fly—no extra “operations” array
  let cumulativeOperations = 0;
  for (let currentIndex = 0; currentIndex < arrayLength; ++currentIndex) {
    cumulativeOperations += differenceArray[currentIndex];

    // If nums[currentIndex] needs more decrements than we've recorded so far, we can’t zero it out
    if (nums[currentIndex] > cumulativeOperations) {
      return false;
    }
  }

  return true;
}
