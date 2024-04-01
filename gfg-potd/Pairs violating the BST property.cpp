Given a binary tree with n nodes, find the number of pairs violating the BST property.
BST has the following properties:-

Every node is greater than its left child and less than its right child.
Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
The maximum in the left sub-tree must be less than the minimum in the right subtree.
Example 1:

Input : 
n = 5
Input tree
    
Output :
5
Explanation : 
Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.
Example 2:

Input : 
n = 6
Input tree

Output :
8
Explanation :
There are total 8 Pairs which violation the BST properties.
Your task :
You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.
 
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)
 
Your Task :
1 <= n <= 2*104
-109 <= node->data <= 109





class Solution {
public:
    void inorder(Node *root, vector<int> &in) {
        if(root) {
            inorder(root->left, in);
            in.push_back(root->data);
            inorder(root->right, in);
        }
    }
    
    int merge(int low, int mid, int high, vector<int> &v) {
        int i = low, j = mid + 1, k = 0, n = high - low + 1, count = 0;
        vector<int> temp(n);
        
        while(i <= mid and j <= high) {
            if(v[i] <= v[j]) {
                temp[k++] = v[i++];
            } else {
                count += mid - i + 1;
                temp[k++] = v[j++];
            }
        }
        
        while(i <= mid)
            temp[k++] = v[i++];
            
        while(j <= high)
            temp[k++] = v[j++];
            
        for(i = low, k = 0; k < n; k++, i++)
            v[i] = temp[k];
            
        return count;
    }
    
    int mergeSort(int low, int high, vector<int> &in) {
        int count = 0;
        
        if(low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(low, mid, in);
            count += mergeSort(mid + 1, high, in);
            count += merge(low, mid, high, in);
        }
        
        return count;
    }

    int pairsViolatingBST(int n, Node *root) {
        vector<int> in;
        inorder(root, in);
        return mergeSort(0, in.size() - 1, in);
    }
};
