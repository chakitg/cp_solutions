You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
Example 2:

Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays): 
   - With no other distinct values (1 array): [1,1,1,1,1] 
   - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
 

Constraints:

2 <= n <= 104
1 <= maxValue <= 104


const MODULO = 10n ** 9n + 7n;
const MAX_VALUE = 10000;

const STRICT_COUNTS = [Array.from({ length: MAX_VALUE }, (_, i) => BigInt(i + 1))];

let prev_row = Array(MAX_VALUE).fill(1n);
let next_row = Array(MAX_VALUE).fill(0n);
let prev_base = 1;

while ((prev_base << 1) <= MAX_VALUE) {
  const next_base = prev_base << 1;

  for (let i = next_base - 1; i < MAX_VALUE; i++) {
    next_row[i] = 0n;
  }

  for (let prev_num = prev_base; prev_num <= MAX_VALUE; prev_num++) {
    const prev_count = prev_row[prev_num - 1];
    for (let mult = 2; ; mult++) {
      const product = prev_num * mult;
      if (product > MAX_VALUE) break;
      next_row[product - 1] = (next_row[product - 1] + prev_count) % MODULO;
    }
  }

  const current_counts = Array(MAX_VALUE + 1 - next_base).fill(next_row[next_base - 1]);
  for (let next_num = next_base + 1; next_num <= MAX_VALUE; next_num++) {
    current_counts[next_num - next_base] =
      (current_counts[next_num - 1 - next_base] + next_row[next_num - 1]) % MODULO;
  }

  STRICT_COUNTS.push(current_counts);
  prev_base = next_base;
  [prev_row, next_row] = [next_row, prev_row];
}

function idealArrays(n, maxValue) {
  let count = 0n;
  let combo = 1n;
  let topFactor = BigInt(n - 1);
  let bottomFactor = 1n;
  let base = 1;

  const maxK = Math.min(n, STRICT_COUNTS.length);

  for (let k = 0; k < maxK; k++) {
    if (base <= maxValue) {
      const idx = maxValue - base;
      count = (count + combo * STRICT_COUNTS[k][idx]) % MODULO;
    } else {
      break;
    }

    combo = (combo * topFactor) / bottomFactor;
    topFactor -= 1n;
    bottomFactor += 1n;
    base <<= 1;
  }

  return Number(count);
}

 
