Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.

Example 1:

Input:
n = 6
s = "ilike"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as "i like".
Example 2:

Input:
n = 6
s = "ilikesamsung"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected Time Complexity: O(len(s)2)
Expected Space Complexity: O(len(s))

Constraints:
1 ≤ n ≤ 12
1 ≤ len(s) ≤ 1100





class Solution
{
public:
    bool solve(string A, unordered_map<string,int>&mp, int ind){
        if(ind>=A.length()){
            return true;
        }
        
        for(int i=ind;i<A.length();i++){
            string s=A.substr(ind, i-ind+1);
            if(mp.find(s)!=mp.end()){
                if(solve(A, mp, i+1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    int func(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>mp;
        for(int i=0;i<B.size();i++){
            mp[B[i]]++;
        }
        
        if(solve(A, mp, 0)){
            return true;
        }
        else{
            return false;
        }
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        return func(s, dictionary);
    }
};
