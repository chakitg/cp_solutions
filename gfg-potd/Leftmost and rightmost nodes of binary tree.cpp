Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:

Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    
Output: 1 2 3 4 7
Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7
Example 2:

Input:

        10
      /    \
     20     30
    / \  
   40  60
Output: 10 20 30 40 60
Your Task:  
You dont need to read input. Complete the function printCorner() which takes root node as input parameter and prints the corner nodes separated by spaces. The left corner should be printed before the right for each level starting from level 0.
Note: Don't print a new line after printing all the corner nodes.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(number of nodes in a level)

Constraints:
1 ≤ N ≤ 10^5



void printCorner(Node *root)
{

// Your code goes here
    if(root==NULL){
        return;
    }
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
        Node *curr=q.front();
        q.pop();
        if(i==0 || i==count-1){
            cout<<curr->data<<" ";
        }
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        }
    }
};
