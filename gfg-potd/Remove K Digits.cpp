Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 
111
Explanation: 
Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.
Example 2:

Input:
S = "1002991", K = 3
Output: 
21
Explanation: 
Remove the three digits 1(leading
one), 9, and 9 to form the new number 21(Note
that the output must not contain leading
zeroes) which is the smallest.
Your Task:
You don't need to read input or print anything. Your task is to complete the function removeKdigits() which takes the string S and an integer K as input and returns the new number which is the smallest possible.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1<= K <= |S|<=106




  class Solution {
  public:
    string removeKdigits(string S, int K) {
        pair<int, int> last = {0, K};
        int n = S.size();
        int index = 0;
        
        while(index < n){
            if(S[index] != '0'){
                if(K)
                    --K;
                else
                    break;
                    
                ++index;
            }
            else{
                while(index < n and S[index] == '0'){
                    ++index;
                }
                
                last = {index, K};
            }
        }
        
        stack<int> num;
        int start = last.first;
        K = last.second;
        
        for(int i = start; i < n; i++){
            while(num.size() and num.top() > (S[i] - '0') and K){
                --K;
                num.pop();
            }
            
            num.push(S[i] - '0');
        }
        
        while(num.size() and K--){
            num.pop();
        }
        
        string ans = "";
        
        while(num.size()){
            ans += to_string(num.top());
            num.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans == "")
            ans = "0";
        
        return ans;
    }
};
