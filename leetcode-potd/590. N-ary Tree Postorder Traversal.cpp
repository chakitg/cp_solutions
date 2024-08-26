Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:


Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:


Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.


class Solution {
public:
    void postorder(vector<int>& v, Node* root) {
        if (root == nullptr) {
            return;
        }
        for (int i = 0; i < root->children.size(); i++) {
            postorder(v, root->children[i]);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        postorder(v, root);
        return v;
    }
};
