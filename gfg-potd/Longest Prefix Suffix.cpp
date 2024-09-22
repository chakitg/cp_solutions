Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets





int lps(string s) {
        // Your code goes here
        int n = s.size();
	    vector<int> LPS(n, 0);
	    int len=0, i=1;
	    while(i<n){
	        if(s[len]==s[i]){
	            LPS[i] = len+1;
	            len++;
	            i++;
	        }else{
	            if(len==0){
	                LPS[i] = 0;
	                i++;
	            }else{
	                len = LPS[len-1];
	            }
	        }
	    }
	    
	    return LPS[n-1];
    }
