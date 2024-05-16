Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.

Example 1:

Input: 
n = 10
edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
Output:
2
Explanation:
Original tree:

   
After removing edge 1-3 and 1-6, each remaining component consists of even number of nodes. 


Example 2:

Input: 
n = 4
edges = {{2,1},{4,2},{1,3}}
Output:
1
Explanation:
After removing 2-1, each remaining component consists of even number of nodes. 
Your Task:
You don't need to read or print anyhting. Your task is to complete the function minimumEdgeRemove() which takes n and edges as input parameters and returns the maximum number of edges that need to be removed from the given tree.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= n <= 105
edges.length == n - 1
1 <= edges[i][0], edges[i][1] <= n





class Solution {
    int components  = 0 ; 
    int  dfs( int src, vector<bool>&visited, vector< int> graph[]  )
    {
         visited[ src] = true;
         int count = 1 ;
         for ( auto adj  : graph [ src ] )
         {
            if ( visited[ adj]==  true )
                continue;
            int res = dfs( adj , visited, graph  );
            if( res %2 == 0 )
            {
                components ++;
            }
            else 
            {
                count += res ;
            }
         }
         return count;
    }
public:
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        vector< int > graph[ n +1 ];
        for ( auto it: edges )
        {
            graph[it[0]].push_back( it[1]);
            graph[it[1]].push_back ( it[0]);
        }
        vector< bool>visited( n + 1 , false ) ;
        dfs ( 1 , visited, graph );
        return components;
    }
};
