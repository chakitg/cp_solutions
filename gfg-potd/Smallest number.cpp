Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

Examples:

Input: s = 9, d = 2
Output: 18 
Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
Input: s = 20, d = 3 
Output: 299 
Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ s ≤ 100
1 ≤ d ≤ 6





class Solution {
  public:
    string smallestNumber(int s, int d) {
        // Aman Yadav
        if((9*d)<s) return "-1";
        string ans="";
        for(int i= d-1;i>=0;i--){
            if(s>9){
                ans='9'+ans;
                s-=9;
            }
            else{
                if(i==0){
                    ans=to_string(s)+ans;
                }
                else{

                ans=to_string(s-1)+ans;
                i--;
                while(i>0){
                    ans='0'+ans;
                    i--;
                }
                ans='1'+ans;
                break;

            }
        }
    }
    return ans;
    }
};
