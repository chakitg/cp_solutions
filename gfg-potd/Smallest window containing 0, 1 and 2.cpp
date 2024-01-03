Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = 12121
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.
Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}




class Solution {
public:
    int smallestSubstring(string S) {
        vector<int> pos(3, -1);
        int out = INT_MAX;
        
        for(int i = 0; i < S.size(); ++i) {
            pos[S[i] - '0'] = i;
            
            int nin = INT_MAX, nax = 0;
            for(auto it: pos) {
                nin = min(nin, it);
                nax = max(nax, it);
            }    
            
            if(nin != -1)
                out = min(out, nax - nin + 1);
        }
        
        return out == INT_MAX ? -1 : out;
    }
};
