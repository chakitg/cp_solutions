The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



Examples:

Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: 4
Output: [[2 4 1 3 ],[3 1 4 2 ]]
Explaination: These are the 2 possible solutions.
Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 

Constraints:
1 ≤ n ≤ 10






class Solution{
public:
bool canPut(int row,int col,vector<int> temp){
        int r = row, c = col;
        while(r>=0 and c>=0){
            if(temp[r]==c+1)return false;
            r--;
            c--;
        }
        r = row, c = col;
        while(r>=0){
            if(temp[r]==c+1)return false;
            r--;
        }
        r = row, c = col;
        while(r>=0 and c<temp.size()){
            if(temp[r]==c+1)return false;
            r--;
            c++;
        }
        return true;
    }
    void help(int n,vector<vector<int>> &ans,vector<int> temp,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPut(row,col,temp)){
                temp[row]=col+1;
                help(n,ans,temp,row+1);
                temp[row]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp(n,0);
        help(n,ans,temp,0);
        return ans;
    }
};
