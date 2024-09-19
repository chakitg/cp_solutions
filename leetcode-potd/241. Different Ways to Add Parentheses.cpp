Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.




class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;

        for(int i = 0 ; i < expression.size() ; i++) {
            char ch = expression[i];

            if(ch == '+' || ch == '-' || ch == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                
                vector<int> L_res = diffWaysToCompute(left);
                vector<int> R_res = diffWaysToCompute(right);

                for(int  l : L_res) {
                    for(int r : R_res) {
                        if(ch == '+') {
                            ans.push_back(l + r);
                        }
                        else if (ch == '-') {
                            ans.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            ans.push_back(l * r);
                        }

                    }
                }
            }
        }

        if(ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};
