// Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

// Recall that the number of set bits an integer has is the number of 1's present when written in binary.

// For example, 21 written in binary is 10101, which has 3 set bits.
 

// Example 1:

// Input: left = 6, right = 10
// Output: 4
// Explanation:
// 6  -> 110 (2 set bits, 2 is prime)
// 7  -> 111 (3 set bits, 3 is prime)
// 8  -> 1000 (1 set bit, 1 is not prime)
// 9  -> 1001 (2 set bits, 2 is prime)
// 10 -> 1010 (2 set bits, 2 is prime)
// 4 numbers have a prime number of set bits.
// Example 2:

// Input: left = 10, right = 15
// Output: 5
// Explanation:
// 10 -> 1010 (2 set bits, 2 is prime)
// 11 -> 1011 (3 set bits, 3 is prime)
// 12 -> 1100 (2 set bits, 2 is prime)
// 13 -> 1101 (3 set bits, 3 is prime)
// 14 -> 1110 (3 set bits, 3 is prime)
// 15 -> 1111 (4 set bits, 4 is not prime)
// 5 numbers have a prime number of set bits.
 

// Constraints:

// 1 <= left <= right <= 106
// 0 <= right - left <= 104





class Solution {
public:
    int countPrimeSetBits(int l, int r) {
 set<int> p = { 2, 3, 5, 7, 11, 13, 17, 19};// max possible prime no. 19.Because of range is 10^6  
        int x=0;
        while((r-l+1)!=0){
        int i=0;
        int y=l;// here we put the value to y because if you use l as code than value of l change.....
        while(y!=0){
        i+=(y&1);
        y=y>>1;
         }
        x+=p.count(i);
        l++;
        }
        return x;
  }
};
