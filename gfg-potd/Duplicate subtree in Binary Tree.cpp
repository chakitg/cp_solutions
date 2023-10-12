Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one. 

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only argument and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
0 ≤ Data of nodes ≤ 9
1 ≤ Number of nodes ≤ 105 



bool same(Node * x, Node * y)
{
    if((x == nullptr) ^ (y == nullptr))
        return 0;
    if((x == nullptr) and (y == nullptr))
        return 1;
    if(x -> data != y -> data)
        return 0;

    return same(x -> left, y -> left) and same(x -> right, y -> right);
}

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root)
    {
        vector<Node *> nodes;

        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node * cur = q.front();
            q.pop();

            bool leaf = 1;

            if(cur -> left != nullptr)
            {
                q.push(cur -> left);
                leaf = 0;
            }
            if(cur -> right != nullptr)
            {
                q.push(cur -> right);
                leaf = 0;
            }

            if(!leaf)
                nodes.push_back(cur);
        }

        for(int i = 0; i < nodes.size(); i++)
        {
            for(int j = i + 1; j < nodes.size(); j++)
            {
                if(same(nodes[i], nodes[j]))
                    return 1;
            }
        }

        return 0;
    }
};
