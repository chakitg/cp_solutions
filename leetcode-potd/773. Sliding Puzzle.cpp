On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
 

Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.




class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        //positions = 6
        //Total possible states = 6!
        //Worst case me visit all states = O(6!)
        //Space : O(6!)
        string target = "123450";
        queue<string> que;
        que.push(start);
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};
        unordered_set<string> visited;
        visited.insert(start);
        int level = 0; //moves
        while(!que.empty()) {
            int n = que.size();
            //Processing all elements at current level
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == target) {
                    return level;
                }
                int indexOfZero = curr.find('0'); //finding index of 0
                for(int swapIdx : mp[indexOfZero]) {
                    string newState = curr;
                    swap(newState[indexOfZero], newState[swapIdx]);
                    if(visited.find(newState) == visited.end()) {
                        que.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
