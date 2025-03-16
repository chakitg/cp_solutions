You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

 

Example 1:

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
Example 2:

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 

Constraints:

1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106



/**
 * @param {number[]} ranks
 * @param {number} cars
 * @return {number}
 */
var repairCars = function(ranks, cars) {
    // MAIN IDEA: Guess the minimum possible time to repair all cars until it is minimal, using Binary Search

    let res = Infinity

    // PHASE 1: Define the search range for Binary Search
    // Left (l): minimum possible time (minimum rank * 1 * 1)
    // Right (r): maximum possible time (maximum rank * cars * cars)
    let l = Math.min(...ranks)
    let r = Math.max(...ranks) * cars * cars

    while (l <= r) {
        let guessTime = Math.floor((l + r) / 2)
        
        // Check if guessTime is a valid candidate
        if (isGood(ranks, guessTime, cars)) {
            res = guessTime
            r = guessTime - 1 // Try to find an even smaller valid time
        } else {
            l = guessTime + 1 // Increase time if the current guess is insufficient
        }
    }

    return res
}


function isGood(ranks, max, cars) {
    let count = 0

    // Derived formula from the repair time equation:
    // 1. ranks[i] * x * x <= max  →  (time needed for x cars by a mechanic)
    // 2. x * x <= max / ranks[i] 
    // 3. x <= max / ranks[i]  →  (maximum cars a mechanic can repair within max time)

    for (let i = 0; i < ranks.length; i++) {
        let temp = Math.floor(max / ranks[i])
        count += Math.floor(Math.sqrt(temp))

        // If the total number of repaired cars meets or exceeds the requirement, the GuessTime is valid
        if (count >= cars) return true
    }


    return false
}
