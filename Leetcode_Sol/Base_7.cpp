// Given an integer num, return a string of its base 7 representation.

 

// Example 1:

// Input: num = 100
// Output: "202"
// Example 2:

// Input: num = -7
// Output: "-10"
 

// Constraints:

// -107 <= num <= 107



class Solution {
public:
    string convertToBase7(int n) {
        string str="";
        int rem;
        int num=abs(n);
        if(n==0) return "0";
        while(num!=0){
            rem=num%7;
            str=to_string(rem)+str;
            num/=7;
        }
        if(n<0) return "-"+str;
        return str;
    }
};
