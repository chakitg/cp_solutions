Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] is either 0 or 1.





class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m =mat[0].size();
        int pos=-1;
        int n =mat.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
//check for number of 1 in each row
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) {
                   count++; 
                   pos=j;
                }
            }
// if there's only one 1 in row ,then we will count total 1 in same column where 1 was found.
            if(count==1){
                count=0;//to count no. of 1 from beginning or you can compare count==2 at last.
                for(int k=0;k<n;k++){
                    if(mat[k][pos]==1) count++;
                }
//if total 1 in a column = 1, ans++
                if(count==1) ans++;
            }
        }
        return ans;
    }
    
};
