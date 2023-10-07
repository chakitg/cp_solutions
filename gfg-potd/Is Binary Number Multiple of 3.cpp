// Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.

// Example 1:

// Input: S = "0011"
// Output: 1
// Explanation: "0011" is 3, which is divisible by 3.
// Example 2:

// Input: S = "100"
// Output: 0
// Explanation: "100"'s decimal equivalent is 4, which is not divisible by 3.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function isDivisible() which takes the string s as inputs and returns 1 if the given number is divisible by 3 otherwise 0.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 105


class Solution{
public:	
		
	int isDivisible(string s){
	    int cur = 1, sum = 0, n = s.size();
	    if(s[n-1] == '1') sum++;
	    
	    for(int i = n-2; i >= 0; i--) {
	        cur = (cur * 2) % 3;
	        if(s[i] == '1') sum = (sum + cur) % 3;
	    }
	    return sum == 0;
	}

};
