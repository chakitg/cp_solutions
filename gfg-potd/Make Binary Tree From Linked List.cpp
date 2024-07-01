Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
The result will be judged by printing the level order traversal of the Binary tree. 
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: list = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Input: list = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2   1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Constraints:
1 <= size(list) <= 105
1 <= node.data <= 105





class Solution { 
  public: 
    TreeNode* build_tree(int i, vector<int>&v, int n){ 
        if(i>=n)return NULL; 
        TreeNode* root=new TreeNode(v[i]); 
        root->left=build_tree(2*i+1,v,n); 
        root->right=build_tree(2*i+2,v,n); 
        return root; 
    } 
    void convert(Node *head, TreeNode *&root) { 
        vector<int>v; 
        Node* ptr=head; 

        while(ptr!=NULL){ 
            v.push_back(ptr->data); 
            ptr=ptr->next; 
        } 
        int n=v.size(); 
        root=build_tree(0,v,n); 
    } 
};
