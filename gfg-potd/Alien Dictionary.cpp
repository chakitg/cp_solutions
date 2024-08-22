Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Expected Time Complexity: O(n * |s| + k)
Expected Auxillary Space: O(k)

Constraints:
1 ≤ n≤ 104
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50






class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int>indegree(k);
        vector<vector<int>>adj(k,vector<int>());
        for(int i=0;i<n-1;i++){
            string str1=dict[i];
            string str2=dict[i+1];
            int len=min(str1.size(),str2.size());
            for(int j=0;j<len;j++){
                if(str1[j] !=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    indegree[str2[j]-'a']++;
                    break;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        string ans="";
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(char(node+'a'));
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
    }


};
