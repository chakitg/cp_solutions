Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same. 

Examples :

Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence
Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets






String removeDups(String str) {
        // code here
          StringBuilder ans = new StringBuilder();
        boolean temp[]=new boolean[26];
        for(int i=0;i<str.length();i++){
            char x = str.charAt(i);
            if(!temp[x-'a']){
                ans.append(x);
                temp[x-'a']=true;
            }
        }
        return ans.toString();
    }
