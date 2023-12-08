Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

 

Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-1000 <= Node.val <= 1000




  class Solution {
public:
    void preorder(TreeNode* root,string& s){
        if(root==NULL) return;
        string temp=to_string(root->val);
        s+='(';
        s+=temp;
        if(root->left==NULL && root->right!=NULL) s+="()";
        preorder(root->left,s);
        preorder(root->right,s);
        s+=')';
    }

    string tree2str(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        //return the string without the first and last parentheses.
        return ans.substr(1,ans.size()-2);
    }
};
