You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000



class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);


        int top = 0, left = 0;
        int bottom = m-1, right = n-1;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        while(head){
            // Right
            for(int i = left; i <= right && head; i++){
                ans[top][i] = head -> val;
                head = head -> next;
            }
            top++;

            //Bottom
            for(int i = top; i <= bottom && head; i++){
                ans[i][right] = head -> val;
                head = head -> next;
            }
            right--;

            // Left
            for(int i = right; i >= left && head; i--){
                ans[bottom][i] = head -> val;
                head = head -> next;
            }
            bottom--;

            //Up
            for(int i = bottom; i >= top && head; i--){
                ans[i][left] = head -> val;
                head = head -> next; 
            }
            left++;
        }

        return ans;
    }
};
