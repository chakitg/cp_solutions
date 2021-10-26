class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *i= root;
        TreeNode *temp=NULL;
        while(i!=NULL)
        {
            temp=i->left;
            i->left=i->right;
            i->right=temp;
            TreeNode *l=invertTree(i->left);
            TreeNode *r=invertTree(i->right);
            if(i==root)
                break;
        }
        return root;
    }
};