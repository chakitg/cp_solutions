Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9





//User function template for C++
class Solution{
    string makePalindrome(string in) {
        int a = 0;
        int b = in.size() - 1;
        while (a < b) {
            in[b] = in[a];
            a++;
            b--;
        }
        return in;
    }

    string solve(string A) {
        int n = A.size();
        string temp = makePalindrome(A);
        if (temp > A) return temp;
        int carry = 1;
        for (int a = (n - 1) / 2; a >= 0; a--) {
            int t = A[a] - '0' + carry;
            if (t == 10) {
                t = 0;
                carry = 1;
            } else carry = 0;
            A[a] = '0' + t;
        }
        string res;
        if (carry == 1) res = "1";
        res += A;
        return makePalindrome(res);
    }
    
    public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    string A;
        for (int i = 0; i < n; i++) A += num[i] + '0';
        string res = solve(A);

        vector<int> ans;
        for (auto i: res)ans.push_back(i - '0');
        return ans;
	}

};
