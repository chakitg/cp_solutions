You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:



Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 

Constraints:

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.






class Solution
{
public:
    // rotateTheBox - stub provided by LeetCode.
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        // Base case - matrix size 1x1.
        if (box.size() == 1ul && box.front().size() == 1ul)
            return box;

        // Go over columns, from last to first.
        const IsStoneOrObstacle func;
        size_t                  row;
        for (int col = box.front().size()-1ul; col != -1; --col)
        {
            // Go over stones of row.
            for (row = 0ul; row != box.size(); ++row)
                if (box[row][col] == '#')
                {
                    // Move stone forward until obstacle or another stone.
                    box[row][col] = '.';
                    box[row][find_if(box[row].begin()+col+1ul, box[row].end(),
                                     func) - box[row].begin() - 1ul] = '#';
                }
        }

        // Rotate matrix clockwise.
        const size_t rowsMinus1 = box.size()-1ul;
        size_t       col;
        if (box.size() == box.front().size())
        {
            // Square matrix - rotate inplace by mirroring lines and transposing.
            const size_t halfRows = box.size() >> 1ul;
            for (row = 0ul; row != halfRows; ++row)
                box[row].swap(box[rowsMinus1-row]);
            for (row = 1ul; row != box.size(); ++row)
                for (col = 0ul; col != row; ++col)
                    swap(box[col][row], box[row][col]);
            return box;
        }

        // Non-square matrix - create new rotated matrix.
        vector<vector<char>> result(box.front().size(),
                                    vector<char>(box.size()));
        for (row = 0ul; row != box.size(); ++row)
            for (col = 0ul; col != box.front().size(); ++col)
                result[col][rowsMinus1 - row] = box[row][col];
        return result;
    }

private:
    // IsStoneOrObstacle - functor to find stones and obstacles.
    struct IsStoneOrObstacle
    {
        bool operator ()(const char c) const
        {
            return c == '#' || c == '*';
        }
    };
};

static const int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
