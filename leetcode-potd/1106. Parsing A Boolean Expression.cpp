A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.




class Solution {
public:
    // Function to parse and evaluate a boolean expression
    bool parseBoolExpr(string expression) {
        stack<char> ops;  // Stack to store operators like '|', '&', and '!'
        stack<char> opr;  // Stack to store operands 't' (true), 'f' (false), and '(' (for parentheses)
        map<char, int> mp;  // Mapping characters 't' and 'f' to their respective boolean values
        mp['f'] = 0;  // 'f' maps to false (0)
        mp['t'] = 1;  // 't' maps to true (1)
        set<char> bops = {'|', '&', '!'};  // Set containing valid boolean operators
        
        // Iterate through each character in the expression
        for(auto &x : expression) {
            if (bops.count(x)) {
                // If the character is a boolean operator, push it onto the ops stack
                ops.push(x);
            }
            else if (x == ')') {
                // If we encounter a closing parenthesis, it means we need to evaluate an expression
                char currops = ops.top();  // Get the most recent operator from the ops stack
                ops.pop();  // Remove the operator from the stack
                
                // Initialize result based on the operator type
                bool ans = (currops == '&') ? true : false;
                if (currops == '!') ans = true;  // Negation (!) starts with true
                
                // Pop and process the operands until we reach the opening parenthesis
                while (!opr.empty() && opr.top() != '(') {
                    char curr = opr.top();  // Get the current operand
                    opr.pop();  // Remove the operand from the stack
                    
                    // Perform the operation based on the current operator
                    if (currops == '|') {
                        ans |= mp[curr];  // OR operation
                    } 
                    else if (currops == '&') {
                        ans &= mp[curr];  // AND operation
                    } 
                    else if (currops == '!') {
                        ans = !mp[curr];  // NOT operation
                    }
                }
                
                // Pop the opening parenthesis '(' from the stack
                if (!opr.empty() && opr.top() == '(') {
                    opr.pop();
                }
                
                // Push the result ('t' or 'f') back onto the operand stack
                opr.push(ans ? 't' : 'f');
            }
            else if (x != ',' && x != '(') {
                // If the character is an operand ('t' or 'f'), push it onto the opr stack
                opr.push(x);
            }
            else if (x == '(') {
                // If the character is an opening parenthesis, push it onto the opr stack
                opr.push(x);
            }
        }
        
        // The final result will be at the top of the opr stack
        return mp[opr.top()];  // Convert the top character to its corresponding boolean value and return
    }
};
