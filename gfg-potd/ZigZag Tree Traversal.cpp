Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

Example 1:

Input:
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
Output:
1 3 2 4 5 6 7
Example 2:

Input:
           7
        /     \
       9      7
     /  \      /   
    8   8  6     
   /  \
  10  9 
Output:
7 7 9 8 8 6 9 10 
Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105




class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector<int>ans;
    vector <int> zigZagTraversal(Node* root)
    {
        if (root==nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        bool left=true;
        while (!q.empty())
        {
            int size=q.size();
            vector<int>vec(size);
            for (int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                int ind=left ? i : (size-1-i);
                vec[ind]=temp->data;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            left=!left;
            ans.insert(ans.end(), vec.begin(), vec.end());
        }
        return ans;
    }
};
