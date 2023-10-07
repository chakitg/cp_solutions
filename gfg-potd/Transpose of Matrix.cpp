// Write a program to find the transpose of a square matrix of size N*N. Transpose of a matrix is obtained by changing rows to columns and columns to rows.

// Example 1:

// Input:
// N = 4
// mat[][] = {{1, 1, 1, 1},
//            {2, 2, 2, 2}
//            {3, 3, 3, 3}
//            {4, 4, 4, 4}}
// Output: 
// {{1, 2, 3, 4},  
//  {1, 2, 3, 4}  
//  {1, 2, 3, 4}
//  {1, 2, 3, 4}} 
// Example 2:

// Input:
// N = 2
// mat[][] = {{1, 2},
//            {-9, -2}}
// Output:
// {{1, -9}, 
//  {2, -2}}

// Your Task:
// You don't need to read input or print anything. Complete the function transpose() which takes matrix[][] and N as input parameters and finds the transpose of the input matrix. You need to do this in-place. That is you need to update the original matrix with the transpose. 

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 103
// -109 <= mat[i][j] <= 109



class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i)
                {
                swap(matrix[i][j],matrix[j][i]);
                
                }
            }
        } 
    }
};
