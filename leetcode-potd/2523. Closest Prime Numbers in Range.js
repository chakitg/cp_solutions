Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106




const isPrimeNumber = (n) => {
    let factors = 0;
    for (let i = 1; i <= Math.sqrt(n); i++) {
        if (n % i === 0) {
            factors += 1;
            if (n / i !== i) {
                factors += 1;
            }
        }
        if (factors > 2) {
            return false;
        }
    }
    return true;
};

var closestPrimes = function (left, right) {
    const primeNumbers = [];
    for (let i = left <= 1 ? 2 : left; i <= right; i++) {
        if (isPrimeNumber(i)) {
            primeNumbers.push(i);
        }
    }
    if (primeNumbers.length <= 1) {
        return [-1, -1];
    }
    const answer = [0, 0];
    let minDiff = Number.MAX_VALUE;
    for (let i = 1; i < primeNumbers.length; i++) {
        const absDiff = Math.abs(primeNumbers[i] - primeNumbers[i - 1]);
        if (absDiff < minDiff) {
            minDiff = absDiff;
            answer[0] = primeNumbers[i - 1];
            answer[1] = primeNumbers[i];
        }
    }
    return answer;
};
