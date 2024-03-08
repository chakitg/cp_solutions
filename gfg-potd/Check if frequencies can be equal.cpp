Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.

Example 1:

Input:
s = "xyyz"
Output: 
1 
Explanation: 
Removing one 'y' will make frequency of each character to be 1.
Example 2:

Input:
s = "xxxxyyzz"
Output: 
0
Explanation: 
Frequency can not be made same by removing at most one character.
Your Task:  
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

Expected Time Complexity: O(|s|) 
Expected Auxiliary Space: O(1)

Constraints:
1 <= |s| <= 105





class Solution{
public:	
	bool sameFreq(string s)
	{
	    int arr[26] = {0};
	    for(char i : s) arr[i-'a']++;
	    int mx = *max_element(arr,arr+26),val = 0,cnt = 0,cnt1 = 0;
	    for(int i=0;i<26;i++){
	        if(arr[i] == mx) cnt++;
	        else if(arr[i]){
	            cnt1++;
	            if(val == 0) val = arr[i];
	            else{
	                if(arr[i] != val) return false;
	            }
	        }
	    }
	    if((cnt > 1 && cnt1 > 1) || (cnt == 1 && cnt1 >= 1 && mx - val > 1) || (cnt1 == 1 && cnt > 1 && val != 1)) return false;
	    return true;
	}
};
