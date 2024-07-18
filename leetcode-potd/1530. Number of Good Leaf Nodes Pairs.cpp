You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

 

Example 1:


Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
Example 2:


Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
1 <= Node.val <= 100
1 <= distance <= 10




class Solution {
public:
    int ans=0;
    vector<int> solve(TreeNode* root,int d){
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {1};
        auto l=solve(root->left,d);
        auto r=solve(root->right,d);
        for(auto ll:l){
            for(auto rr:r){
                if(ll+rr<=d) ans++;
            }
        }
        vector<int> curr;
        for(auto it:l) {
            if(1+it<=d) curr.push_back(it+1);
        }
        for(auto it:r) {
            if(1+it<=d) curr.push_back(it+1);
        }
        return curr;


    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return ans;
    }
};
