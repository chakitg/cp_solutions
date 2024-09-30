Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O((m+n)*log(m+n))
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes, value of nodes ≤ 105



class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(vector<int> &ans1, vector<int> &ans2)
    {
        int i = 0, j = 0;
        vector<int> ans;
        int n1 = ans1.size(), n2 = ans2.size();
        while (i < n1 && j < n2)
        {
            if (ans1[i] >= ans2[j])
            {
                ans.push_back(ans2[j]);
                j++;
            }
            else
            {
                ans.push_back(ans1[i]);
                i++;
            }
        }
        while (i < n1)
        {
            ans.push_back(ans1[i]);
            i++;
        }
        while (j < n2)
        {
            ans.push_back(ans2[j]);
            j++;
        }
        return ans;
    }
    void f(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        f(root->left, ans);
        ans.push_back(root->data);
        f(root->right, ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans1, ans2;
        f(root1, ans1);
        f(root2, ans2);
        vector<int> ans = merge(ans1, ans2);
        return ans;
    }
};
