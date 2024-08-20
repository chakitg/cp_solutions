Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ number of nodes ≤ 105

1 ≤ values of nodes ≤ 105






class Solution {
  public:
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,bool> vis;
    Node *tar  =nullptr;
    int minTime(Node* root, int target) 
    {
        dfs1(root,target);
        return dfs2(tar)-1;
    }
    void dfs1(Node *root,int target){
        if(root == nullptr){
            return;
        }
        if(root->data == target){
            tar = root;
        }
        if(root->left != nullptr){
            par[root->left] =root;
        }if(root->right != nullptr){
            par[root->right]= root;
        }
        dfs1(root->left,target);
        dfs1(root->right,target);
    }
    int dfs2(Node* from){
        if(from == nullptr){
            return 0;
        }
        int lft = 0, rgt = 0, parent = 0;
        vis[from] =true;
        if(vis.find(from->left) == vis.end()){
            lft = dfs2(from->left);
        }
        if(vis.find(from->right) == vis.end()){
            rgt = dfs2(from->right);
        }
        if(par.find(from) != par.end() && vis.find(par[from]) == vis.end()){
            parent = dfs2(par[from]);
        }
        return 1 + max(max(lft, rgt), parent);
    }
};
