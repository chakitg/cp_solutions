class Solution {
  public:
   void inorder(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
          vector<int> ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]){
                return false;
            }
        }
        return true;
    }
};
