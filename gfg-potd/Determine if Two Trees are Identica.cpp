Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3
Output: 
Yes
Explanation: 
There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
Example 2:

Input:
    1       1
  /  \     /  \
 2    3   3    2
Output: 
No
Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 105
1 <=Data of a node <= 109



class Solution
{
    public:
    bool isSame(Node * r1, Node * r2){
        if((r1 == nullptr) ^ (r2 == nullptr))
            return 0;
        
        return (r1 == nullptr) or (r1 -> data == r2 -> data);
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        bool ok = isSame(r1, r2);
        
        if(r1){
            ok = ok and isIdentical(r1 -> left, r2 -> left) and isIdentical(r1 -> right, r2 -> right);
        }
        
        return ok;
    }
};
