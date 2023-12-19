An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

 

Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
 

Constraints:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255





class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& a) {
        int i,j,c=0,s=0;
        int n=a.size();
        int m = a[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(i=0;i<n;i++){
            
            for(j=0;j<m;j++){
                c=0;
                s=0;

                int x1,y1,x2,y2;
                x1=i-1>=0?i-1:0;
                x2=i+1<n?i+1:n-1;
                y1=j-1>=0?j-1:0;
                y2=j+1<m?j+1:m-1;

                for(int x=x1;x<=x2;x++){
                    for(int y=y1;y<=y2;y++){
                        c+=a[x][y];
                        s++;
                    }
                }
                
            ans[i][j]=c/s;
                
            }
        }

        return ans;
    }
};
