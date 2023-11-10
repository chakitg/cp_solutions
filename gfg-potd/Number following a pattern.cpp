Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
Example 2:

Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
Your Task:

You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ Length of String ≤ 8




class Solution{   
public:
    string printMinNumberForPattern(string S){
        vector<pair<char, int>> col;
        char curr = S[0];
        int c = (S[0] == 'I');
        
        for (auto i: S){
            if (i == curr)
                ++c;
            else{
                col.push_back({curr, c});
                c = 1;
                curr = i;
            }
        }               
        if (S.back() == 'I')
            ++c;
        col.push_back({curr, c});
        
        string out;
        c = 1;
        for (auto i: col){
            char op = i.first;
            int cnt = i.second + (op == 'D'? 1: -1);
            string temp;
            while (cnt--){
                temp += (char)('0' + c++);
            }
            if (op == 'D')
                reverse(temp.begin(), temp.end());
            out += temp;
        }
        return out;
    }
};
