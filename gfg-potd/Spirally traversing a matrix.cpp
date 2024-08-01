You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= matrix.size(), matrix[0].size() <= 100
0 <= matrix[i][j]<= 100




class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // Aman Yadav
        int row=matrix.size();
        int col=matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        vector<int>ans;
        
        int firstRow=0;
        int firstCol=0;
        int lastRow=row-1;
        int lastCol=col-1;
        
        
        
        while(count<total)
        {
            
            for(int i=firstCol;i<=lastCol && count< total;i++)
            {
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            
            for(int i=firstRow;i<=lastRow && count< total;i++)
            {
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;
            
            for(int i=lastCol;i>=firstCol && count< total;i--)
            {
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            
            for(int i=lastRow;i>=firstRow && count< total;i--)
            {
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }
    return ans;
    }
};
