Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104






class Solution {
    int n;
    int dp[102][102][2];
private:
    int f(int ind, int M, int isAlice, vector<int>& piles){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][M][isAlice]!=-1) return dp[ind][M][isAlice];
        int ans = isAlice ? INT_MIN : INT_MAX;
        int sum = 0;
        for(int x=1; x<=min(2*M,n-ind); x++){
            sum += piles[ind+x-1];
            if(isAlice){ // maximise stones in Alice's turn
                ans = max(ans, sum + f(ind+x, max(M,x), 1-isAlice, piles));
            }
            else{ // minimise stones in Bob's turn
                ans = min(ans, f(ind+x, max(M,x), 1-isAlice, piles));
            }
        }
        return dp[ind][M][isAlice] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return f(0,1,1,piles);
    }
};
