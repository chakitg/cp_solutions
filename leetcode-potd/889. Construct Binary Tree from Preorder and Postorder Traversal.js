Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.



  /**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

var constructFromPrePost = function (preorder, postorder) {
    if (!preorder.length || !postorder.length) return null;
    let preIndex = 0;
    let postIndex = 0;

    function buildTree() {
        let root = new TreeNode(preorder[preIndex++]);

        if (root.val !== postorder[postIndex]) {
            root.left = buildTree();
        }

        if (root.val !== postorder[postIndex]) {
            root.right = buildTree();
        }

        postIndex++;
        return root;
    }
    return buildTree();
};
