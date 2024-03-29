Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 

For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 105





/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> v;
    if(root == NULL)
    return v;
 
   queue<Node*> q;
   q.push(root);
   int level=1;
   
   while(!q.empty()){
       int n =q.size();
       
       if(level%2==0){
       while(n--){
           Node* temp=q.front();
           v.push_back(temp->data);
           q.pop();
           
           if(temp->left!=NULL)q.push(temp->left);
           if(temp->right!=NULL)q.push(temp->right);
       }
       level++;
   }
   else
       {
           stack<Node*> s;
           while(n--)
           {
               Node* temp=q.front();
               s.push(temp);
               q.pop();
           
               if(temp->left!=NULL)q.push(temp->left);
               if(temp->right!=NULL)q.push(temp->right);
           }
           while(!s.empty()){
               v.push_back(s.top()->data);
               s.pop();
           }
           level++;
       }
   }
   return v;
}
