Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.





class Solution {
public:
    string fractionAddition(string s) {
        vector<int> nums;
        vector<int> dens;
        int sz = s.size();
        int i = 0;
        bool isPositive = true;
        while(i < sz){
            if(s[i] == '+' or s[i] == '-'){
                if(s[i] == '-') isPositive = false;
                i++;
            }
            int num = 0;
            while(s[i] >= '0' and s[i] <= '9'){
                num = num*10 + (s[i] - '0');
                i++;
            }
            i++;
            int den = 0;
            while(s[i] >= '0' and s[i] <= '9'){
                den = den*10 + (s[i] - '0');
                i++;
            }
            if(isPositive == false) num *= -1;
            nums.push_back(num);
            dens.push_back(den);
            isPositive = true;
        }
        int szFractions = dens.size();
        int lcm = 1;
        for(int i = 0 ; i < szFractions ; i++){
            lcm = (lcm * dens[i]) / __gcd(lcm, dens[i]);
        }
        int numerator = 0;
        for(int i = 0 ; i < szFractions ; i++){
            numerator += ((lcm / dens[i]) * nums[i]);
        }
        if(numerator == 0) return "0/1";
        int GCD = __gcd(numerator, lcm);
        if(GCD < 0) GCD *= -1;
        return to_string(numerator / GCD) + "/" + to_string(lcm / GCD);
    }
};
