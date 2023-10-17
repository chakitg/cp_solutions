You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:


Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
 

Constraints:

n == leftChild.length == rightChild.length
1 <= n <= 104
-1 <= leftChild[i], rightChild[i] <= n - 1


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        
        // Calculate in-degrees for each node
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false; // More than one incoming edge to a node
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false; // More than one incoming edge to a node
                }
            }
        }
        
        int rootNode = -1;
        // Find the root node (a node with in-degree 0)
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (rootNode != -1) {
                    return false; // More than one root node
                }
                rootNode = i;
            }
        }
        
        if (rootNode == -1) {
            return false; // No root node found
        }
        
        // Perform a depth-first traversal to check if the tree is connected
        vector<bool> visited(n, false);
        stack<int> dfs;
        dfs.push(rootNode);
        
        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();
            
            if (visited[node]) {
                return false; // Cycle detected
            }
            
            visited[node] = true;
            
            if (leftChild[node] != -1) {
                dfs.push(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                dfs.push(rightChild[node]);
            }
        }
        
        // Check if all nodes are visited
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false; // Some nodes are not reachable
            }
        }
        
        return true;
    }
};
