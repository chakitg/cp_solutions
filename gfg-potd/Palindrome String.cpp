Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
Your Task:
You don't need to read input or print anything. Complete the function isPalindrome()which accepts string S and returns an integer value 1 or 0.

Expected Time Complexity: O(Length of S)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Length of S<= 2*105


class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int i=0,j=S.size()-1;
     int ans=1;
     while(i<j){
         if(S[i]!=S[j]){
             ans=0;
             break; 
         }
         i++;j--;
     }
     return ans;
	}

};
