In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6



/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */


function minDominoRotations(tops, bottoms) {
    let result = -1;

    for (let j = 1; j <= 6; j++) {
        let topswap = 0;
        let bottomswap = 0;
        let valid = true;

        for (let i = 0; i < tops.length; i++) {
            if (tops[i] !== j && bottoms[i] !== j) {
                valid = false;
                break;
            }

            if (tops[i] !== j) topswap++;
            if (bottoms[i] !== j) bottomswap++;
        }

        if (valid) {
            let minSwaps = Math.min(topswap, bottomswap);
            if (result === -1 || minSwaps < result) {
                result = minSwaps;
            }
        }
    }

    return result;
}
