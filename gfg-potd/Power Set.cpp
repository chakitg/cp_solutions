Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s will constitute of lower case english alphabets




class Solution {
public:
    vector<string> out;
    string curr;
    
    void subSeq(int i, string &s) {
        if (i == s.size()) {
            if (curr.size())
                out.push_back(curr);
            return;
        }
        
        curr.push_back(s[i]);
        subSeq(i + 1, s);
        curr.pop_back();
        subSeq(i + 1, s);
    }
    
    vector<string> AllPossibleStrings(string s) {
        subSeq(0, s);
        sort(out.begin(), out.end());
        return out;
    }
};
