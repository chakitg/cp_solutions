Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

Constraints:

1 <= num1, num2 <= 109



var minimizeXor = function(num1, num2) {
    let a = num1.toString(2).replace(/0/g, '').length;
    let b = num2.toString(2).replace(/0/g, '').length;
    let res = num1;
    for (let i = 0; i < 32; i++) {
        if (a > b && (1 << i) & num1) {
            res ^= 1 << i;
            a--;
        }
        if (a < b && !((1 << i) & num1)) {
            res ^= 1 << i;
            a++;
        }
    }
    return res;
};
