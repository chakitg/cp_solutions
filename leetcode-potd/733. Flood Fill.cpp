An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n



class Solution {
public:
    void bfs(int prevcolor,int row,int col,int color,vector<vector<int>>&visited,vector<vector<int>>&image)
    {
        // it'll ease the work
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col]=1;

        while(!q.empty())
        {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            // if img is of the starting color.
            if(image[row][col]==prevcolor) image[row][col]=color;

            // up
            if(row-1>=0 && !visited[row-1][col] && image[row-1][col]==prevcolor) q.push({row-1,col}),visited[row-1][col]=1, image[row-1][col]=color;

            // right
            if(col+1<image[0].size() &&  !visited[row][col+1] && image[row][col+1]==prevcolor) q.push({row,col+1}),visited[row][col+1]=1, image[row][col+1]=color;

            //down
            if(row+1<image.size() && !visited[row+1][col] && image[row+1][col]==prevcolor) q.push({row+1,col}),visited[row+1][col]=1, image[row+1][col]=color;

            // left
            if(col-1>=0 && !visited[row][col-1] && image[row][col-1]==prevcolor) q.push({row,col-1}),visited[row][col-1]=1, image[row][col-1]=color;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int prevcolor = image[sr][sc];

          // visiting array.
          vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));

          bfs(prevcolor,sr,sc,color,visited,image);

          return image;
    }
};
