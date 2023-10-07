Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting the value.

Example 1:

Tree = 
        4
      /   \
     2     6
    / \   / \  
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5    
      /   \
     2     6
    / \     \  
   1   3     7

Input: Value to be deleted = 1
Output:
        5    
      /   \
     2     6
      \     \  
       3     7

Input: Value to be deleted = 3
Output:
        5    
      /   \
     2     6
            \  
             7

Input: Value to be deleted = 6
Output:
        5    
      /   \
     2     7

Your Task:  
You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to be deleted as input parameters and returns the root of the modified tree.

Note: The tree will be checked after each deletion. 
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all deletion are successful, inorder traversal of tree will be printed.
If every single node is deleted from tree, 'null' will be printed.

Expected Time Complexity: O(height of tree)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 500



int height(Node *root){
    if(!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
}
int bf(Node *root){
    if(!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return rightHeight-leftHeight;
}
Node *leftRotation(Node *x){
    Node *y = x->right;
    Node *T = y->left;
    
    x->right = T;
    y->left = x;
    return y;
}
Node *rightRotation(Node *x){
    Node *y = x->left;
    Node *T = y->right;
    
    x->left = T;
    y->right = x;
    return y;
}
int findMax(Node *head){
    if(!head)
        return -1;
    while(head->left){
        head = head->left;
    }
    return head->data;
}
Node* deleteNode(Node* root, int data)
{
    //add code here,
    if(!root)
        return root;
    if(root->data<data)
        root->right = deleteNode(root->right,data);
    else if(root->data>data)
        root->left = deleteNode(root->left,data);
    else{
          if(!root->left and !root->right){
              Node *temp = root;
              root = NULL;
              delete(temp);
          }else if(!root->right){
              Node *temp = root;
              root = root->left;
              delete(temp);
          }else if(!root->left){
              Node *temp = root;
              root = root->right;
              delete(temp);
          }else{
              int maximum = findMax(root->right);
              root->data = maximum;
              root->right = deleteNode(root->right,maximum);
          }
    }
        if(!root)
            return root;
        int bff = bf(root);
          if(bff>1 and bf(root->right)>=0)
                return leftRotation(root);
          else if(bff<-1 and bf(root->left)<=0)
                return rightRotation(root);
          else if(bff>1 and bf(root->right)<0){
                root->right = rightRotation(root->right);
                return leftRotation(root);
          }
          else if(bff<-1 and bf(root->left)>0){
                root->left = leftRotation(root->left);
                return rightRotation(root);
          }
    return root;
};
