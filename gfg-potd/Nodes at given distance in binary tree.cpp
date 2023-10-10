Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
Note:

You have to return the list in sorted order.
The tree will not contain duplicate values.
Example 1:

Input:      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14
Target Node = 8
K = 2
Output: 10 14 22
Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.

Example 2:

Input:      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    
Target Node = 7
K = 2
Output: 1 24
Your Task:  
You don't need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target, and K as input parameters and returns a list of nodes at k distance from target in a sorted order.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(Height of tree)

Constraints:
1 ≤ N ≤ 105
1 ≤ data of node ≤ 109
1 ≤ target ≤ 109
1 ≤ k ≤ 20



class Solution {
public:
    vector<int> out;
    
    void trace(Node* node, int k)
    {
        if (!node || k < 0)
            return;

        if (k == 0)
        {
            out.push_back(node->data);
            return;
        }

        trace(node->left, k - 1);
        trace(node->right, k - 1);
    }

    int findDist(Node* node, int target, int k)
    {
        if (!node)
            return INT_MIN;

        if (node->data == target)
        {
            trace(node, k);
            return k - 1;
        }

        int fromLeft = findDist(node->left, target, k);
        if (fromLeft != INT_MIN)
        {
            if (fromLeft == 0)
                out.push_back(node->data);
            else if (fromLeft > 0)
                trace(node->right, fromLeft - 1);

            return fromLeft - 1;
        }

        int fromRight = findDist(node->right, target, k);
        if (fromRight != INT_MIN)
        {
            if (fromRight == 0)
                out.push_back(node->data);
            else if (fromRight > 0)
                trace(node->left, fromRight - 1);

            return fromRight - 1;
        }

        return INT_MIN;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k)
    {
        out = vector<int>(0);
        findDist(root, target, k);
        sort(out.begin(), out.end());
        return out;
    }
};
