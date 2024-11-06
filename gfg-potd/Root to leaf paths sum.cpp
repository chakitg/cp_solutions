class Solution {
  public:
    void pre(Node *start,int sum , int &total_sum){
        if(start == NULL) return;
        sum = 10*sum+ start->data;
        if(start->left == NULL and start->right == NULL){
            total_sum += sum;
            return;
            // cout<<sum<<" ";
        }
        pre(start->left,sum,total_sum);
        pre(start->right,sum,total_sum);
    }
    int treePathsSum(Node *root) {
        int sum = 0;
        int total_sum = 0;
        pre(root,sum,total_sum);
        return total_sum;
    }
};
