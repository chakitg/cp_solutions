Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Example 1:

Input:
      1
    /   \
   2     3
Output: 
2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 
40 20 60 10 30
Your Task:
The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(Number of nodes).
Expected Auxiliary Space: O(Number of nodes).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 109




class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.

    void inorder(Node* root, vector<int>&v)
    {
        if(root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>v;
        inorder(root,v);
        return v;
    }

        Node* buildtree(vector<int> &v,int s,int e)
        {
        if(s >= e) return NULL;
        auto mid = s + (e-s) /2;
        Node* root = new Node(v[mid]);
        root->left = buildtree(v,s,mid);
        root->right = buildtree(v,mid+1,e);
        return root;
    }

    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {


       return buildtree(A,0,A.size());
    }

};
