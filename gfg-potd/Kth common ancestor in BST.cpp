Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a BST, and x != y.

Example 1:

Input: 
Input tree

k = 2, x = 40, y = 60 
Output:
30
Explanation:
Their 2nd common ancestor is 30.
Example 2:

Input: 
Input tree

k = 2, x = 40, y = 60
Output:
-1
Explanation:
LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.
Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
Expected Time Complexity: O(Height of the Tree)
Expected Space Complexity: O(Height of the Tree)
 
Your Task :
1 <= n, k <= 105
1 <= node->data, x, y <= 109







class Solution
{
    public:
    
    /*You are required to complete below function */
    Node* findLCA(Node* node, int x, int y){
        if(node==nullptr){
            return nullptr;
        }
        if(node->data==x || node->data==y){
            return node;
        }
        Node* left = findLCA(node->left, x, y);
        Node* right = findLCA(node->right, x, y);
        if(left && right){
            return node;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return nullptr;
    }
    bool dfs(Node *node, Node* lca, vector<int> &path){
        if(node==nullptr){
            return false;;
        }
        /*cout << node->data << " ";*/
        path.push_back(node->data);
        if(node==lca){
            return true;
        }
        if(dfs(node->left, lca, path)){
            return true;
        }
        if(dfs(node->right, lca, path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        Node* lca = findLCA(root, x, y);
        vector<int> path;
        dfs(root, lca, path);
        if(path.size()<k){
            return -1;
        }
        return path[path.size()-k];

    }
};
