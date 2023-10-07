// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"
 

// Constraints:

// 1 <= num1.length, num2.length <= 104
// num1 and num2 consist of only digits.
// num1 and num2 don't have any leading zeros except for the zero itself.






class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += num1[i--] - '0';
      if (j >= 0)
        carry += num2[j--] - '0';
      ans += carry % 10 + '0';
      carry /= 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
