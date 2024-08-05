Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105





class Solution {
  public:
    vector <int> bottomView(Node *root)
    {
        vector <int> res;
        if (root == NULL)
            return res;

        //initializing a variable 'hd' with 0 for the root element.
        int hd = 0;

        //TreeMap which stores key value pair sorted on key value.
        map<int, int> m;
        map<Node  *, int> mh;

        //Queue to store tree nodes in level order traversal.
        queue<Node *> q;

        //assigning initialized horizontal distance value to 
        //root node and adding it to the queue.
        mh[root] = hd;
        q.push(root);


        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            //extracting the horizontal distance value from dequeued tree node.
            hd = mh[temp];

            //putting the dequeued tree node to TreeMap having key as  
            //horizontal distance. Every time we find a node having same
            //horizontal distance we need to replace the data in the map.
            m[hd] = temp->data;

            //if the dequeued node has a left child, adding it to 
            //the queue with a horizontal distance hd-1.
            if (temp->left != NULL)
            {
                mh[temp->left] = hd-1;
                q.push(temp->left);
            }

            //if the dequeued node has a right child adding it to 
            //the queue with a horizontal distance hd+1.
            if (temp->right != NULL)
            {
                mh[temp->right] = hd+1;
                q.push(temp->right);
            }
        }

        //traversing the map elements and storing nodes in the list.
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            res.push_back (i->second);

        //returning the output list.
        return res;
    }
};
