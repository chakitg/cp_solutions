A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

Example 1:


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
Example 3:


Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
 

Constraints:

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i




/**
 * @param {number[]} favorite
 * @return {number}
 */
const maximumInvitations = (fav, n = fav.length) => {
    let inDegree = new Array(n).fill(0), pairs = [], reverseMap = {}, maxResult = 0;

    for (let i = 0; i < n; i++) {
        inDegree[fav[i]]++;
        if (fav[fav[i]] === i && fav[i] > i) {
            pairs.push([i, fav[i]]);
        }
        if (!(fav[i] in reverseMap)) {
            reverseMap[fav[i]] = [];
        }
        reverseMap[fav[i]].push(i);
    }

    let stack = [];
    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 0) {
            stack.push(i);
        }
    }

    while (stack.length > 0) {
        let current = stack.pop();
        inDegree[fav[current]]--;
        if (inDegree[fav[current]] === 0) {
            stack.push(fav[current]);
        }
    }

    for (let i = 0; i < n; i++) {
        if (inDegree[i] === 1) {
            let count = 1, start = i;
            while (fav[start] !== i) {
                inDegree[start]--;
                start = fav[start];
                count++;
            }
            maxResult = Math.max(maxResult, count);
        }
    }

    let pairSum = 0;
    for (let pair of pairs) {
        const maxChain = [1, 1];
        for (let i = 0; i < 2; i++) {
            let stack = [[pair[i], 1]];
            while (stack.length > 0) {
                let [current, length] = stack.pop();
                if (!(current in reverseMap)) {
                    maxChain[i] = Math.max(maxChain[i], length);
                    continue;
                }
                for (let neighbor of reverseMap[current]) {
                    if (neighbor === fav[pair[i]]) continue;
                    stack.push([neighbor, length + 1]);
                }
            }
        }
        pairSum += maxChain[0] + maxChain[1];
    }

    maxResult = Math.max(maxResult, pairSum);

    return maxResult;
};
