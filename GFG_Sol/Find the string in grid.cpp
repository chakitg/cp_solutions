Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting from the same coordinates, the list should contain the coordinates only once. 

Example 1:

Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.
Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.
Your Task:
You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containing the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Expected Time Complexity: O(n*m*k) where k is constant
Expected Space Complexity: O(1)

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 15



class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>ans;
            int n=grid.size();
    int m=grid[0].size();
    if(word.size()==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str="";
                 str+=grid[i][j];
                 if(str==word){
                     vector<int>temp(2,0);
                     temp[0]=i;
                     temp[1]=j;
                     ans.push_back(temp);
                 }
            }
        }
        return ans;
    }
 
    int dx[8]={-1,-1,-1,0,1,+1,+1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
 
    set<pair<int,int>>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int r=0;r<8;r++){
            string str="";
            str+=grid[i][j];
            int x1=i;
            int y1=j;
                while(x1<n&&y1<m&&x1>=0&&y1>=0){
                    x1+=dx[r];
                    y1+=dy[r];
                    if(x1<n&&y1<m&&x1>=0&&y1>=0){
                        str+=grid[x1][y1];
                    }
                    else{
                        break;
                    }
                    if(str.size()!=word.size()){
                        continue;
                    }
                      if(str==word){
                        temp.insert({i,j});
                       // break;
                    }
                   
                }
            }
        }
    }
    while(!temp.empty()){
        auto it=*(temp.begin());
        vector<int> t(2,0);
        t[0]=it.first;
        t[1]=it.second;
        temp.erase(it);
        ans.push_back(t);
    }
    if(ans.size()==0){
       return {{-1}};
    }
    return ans;
	}
};
