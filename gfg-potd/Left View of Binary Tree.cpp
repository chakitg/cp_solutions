Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105






vector<int> leftView(Node *root)
{
   // Your code here

   // vector to store the answer
   vector<int> ans;

   // queue to store and perform level order traversal
   queue<Node*> q;

   // push root node to queue
   q.push(root);

   // performing level-order traversal
   while(!q.empty()){

       int sz=q.size();

       // iterate over elements on a particular level
       for (int i=0;i<sz;i++){

           Node* curr=q.front();
           q.pop();

           // i=0 means first left element in that particular level so store it in answer vector
           if(i==0){ 
               ans.emplace_back(curr->data);
           }

           // curr node has left push it into queue 
           if(curr->left) {
               q.push(curr->left);
           }

           // curr node has right push it into queue
           if(curr->right){
               q.push(curr->right);
           }
       }
   }

   // return answer vector
   return ans;
}
