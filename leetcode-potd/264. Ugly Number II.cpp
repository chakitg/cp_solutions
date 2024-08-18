An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690



  class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        arr[1]=1;

        int a=1;
        int b=1;
        int c=1;
        for(int i=2;i<=n;i++){
            int i1= arr[a]*2;
            int i2= arr[b]*3;
            int i3= arr[c]*5;
            int num = min({i1,i2,i3});
            arr[i]=num;
            if(num==i1)  a++;
            if(num==i2)  b++;
            if(num==i3)  c++;
        }
        return arr[n];
    }
};
