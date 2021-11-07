// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.



class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
      return "0";

    vector<int> arr(num1.length() + num2.length(), 0);
    for(int i = num1.length()-1; i >= 0; i--){
      for(int j = num2.length()-1; j >= 0; j--){
        int multi = (num1[i]-'0') * (num2[j]-'0') + arr[i+j+1];
        arr[i+j+1] = multi % 10;
        arr[i+j] += multi / 10;
      }
    }
    int index= 0;
    string result = "";
    while(arr[index] == 0) index++;
    for(int i = index; i < arr.size(); i++)
      result += arr[i]+'0';

    return result;
    }
};