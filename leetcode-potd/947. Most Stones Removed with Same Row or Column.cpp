On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.



class Solution {
public:
    
    // store same row or col cords index in Rowlist and Collist
    unordered_map<int,vector<int>>Rowlist;
    unordered_map<int,vector<int>>Collist;
    
    void dfs (int index, vector<bool>&visited, vector<vector<int>>&stones)
    {
        visited[index] = true;
        
        for(int i=0;i<Rowlist[stones[index][0]].size();i++)
        {
            if(visited[Rowlist[stones[index][0]][i]])continue;
            dfs(Rowlist[stones[index][0]][i],visited,stones);
        }

        for(int i=0;i<Collist[stones[index][1]].size();i++)
        {
            if(visited[Collist[stones[index][1]][i]])continue;
            dfs(Collist[stones[index][1]][i],visited,stones);
        }
        
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        // total stones
        int n = stones.size();
        
        // visited stones track
        vector<bool>visited(n,false);

        // store same row or col cords index in Rowlist and Collist 
        for(int i=0;i<n;i++)
        {
            Rowlist[stones[i][0]].push_back(i);
            Collist[stones[i][1]].push_back(i);
        }
        
        // count the connected components 
        int c = 0;
        
        // loop through stones and call DFS for unvisited stones 
        // and count number of connected components
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            dfs(i,visited,stones);
            c++;
        }
        
        // total stones - no of connected components
        return n-c;
    }
};
