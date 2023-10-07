You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and reverses the given stack.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of the stack <= 104
-109 <= Each element of the stack <= 109
Sum of N over all test cases doesn't exceeds 106
Array may contain duplicate elements. 



class Solution{
public:
    void ib(stack<int>&St,int x){
        if(St.empty()){
            St.push(x);
            return;
        }
        int y=St.top();
        St.pop();
        ib(St,x);
        St.push(y);
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        int x=St.top();
        St.pop();
        Reverse(St);
        ib(St,x);
    }
};
