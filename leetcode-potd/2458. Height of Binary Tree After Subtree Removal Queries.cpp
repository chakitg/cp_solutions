You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

Example 1:


Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
Example 2:


Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
m == queries.length
1 <= m <= min(n, 104)
1 <= queries[i] <= n
queries[i] != root.val




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    int mp[100001]={0};

    int dfs(TreeNode* curr,int level,vector<vector<pair<int,int>>>&vec)
    {
        if(!curr)
            return -1;

        //later using this mp you can find the level of any node in O(1)
        mp[curr->val]=level;

        int l=1+dfs(curr->left,level+1,vec);
        int r=1+dfs(curr->right,level+1,vec);
        int h=max(l,r);

        //store  the highest and second highest depth of each level in vec
        if(vec[level][0].second<=h)
        {
            auto pr=vec[level][0];
            vec[level][0]={curr->val,h};
            vec[level][1]=pr;
        }
        else if(vec[level][1].second<=h)
        {
            vec[level][1]={curr->val,h};
        }
        
        //maximum depth of a node is maximum of its left and right child
        return max(l,r);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=100001;
        
        memset(mp,-1,sizeof(mp));

        vector<vector<pair<int,int>>>vec(n,vector<pair<int,int>>(2,{0,0}));

        //mxht means Maximum height
        int mxht=dfs(root,0,vec);

        vector<int>ans;

        for(auto nd:queries)
        {
            auto &v=vec[mp[nd]];

            int x=mxht;
            
            //(v[0].first==nd) means => If the node i am deleting has the highest depth in this level. 
            //Then the new max height of the tree will be the  level i am standing at (mp[v[1].first]) + second highest depth in that level (v[1].second)


            // if(v[0].first != nd) means => If the node i am deleting is not the node with highest depth in the level then the height will not change at all.


            // (v[1].first==0) means=> If the level has only one node then the new height will be maximum height - the level of the node where i am standing now

            if(v[0].first==nd)
            {
                x=(v[1].first==0)?(mp[v[0].first]-1):mp[v[1].first]+v[1].second;
            }
            ans.push_back(x);    
        }

        return ans;
    }
};
