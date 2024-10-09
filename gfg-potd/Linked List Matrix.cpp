Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= mat.size() <=15
1 <= mat[i][j] <=104





  class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        Node* head = new Node(mat[0][0]);
        Node* temp = head;
        for(int i=1;i<n;i++){
            int num = mat[0][i];
            Node* node = new Node(num);
            temp->right = node;
            temp = node;
        }
        temp = head;
        Node* up = head;
        Node* start = head;
        for(int i=1;i<n;i++){
            start->down = new Node(mat[i][0]);
            up = start->right;
            start = start->down;
            temp = start;
            for(int j=1;j<n;j++){
                int num = mat[i][j];
                Node* node = new Node(num);
                temp->right = node;
                temp = node;
                up->down = temp;
                up = up->right;
            }
        }
        return head;
    }
};
