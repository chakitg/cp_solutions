Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

Expected Time Complexity: O(n * log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105




class Solution {
public:
    bool is_prime(int n){
        if(n == 1)
            return false;
        
        for(int i = 2; i <= sqrt(n); ++i)
            if(n % i == 0)
                return false;
        
        return true;
    }
    
    int sumOfDigits(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
  
    int sumOfPrimeFactor(int n){
        int f = 1;
        int sum = 0;
        while(n > 1){
            ++f;
            if(!is_prime(f))
                continue;
                
            while(n % f == 0){
                sum += sumOfDigits(f);
                n /= f;
            }
        }
        return sum;
    }
  
    int smithNum(int n) {
        if(is_prime(n))
            return 0;
        
        return sumOfPrimeFactor(n) == sumOfDigits(n);
    }
};
